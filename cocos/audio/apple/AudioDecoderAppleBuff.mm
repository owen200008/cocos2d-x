/****************************************************************************
 Copyright (c) 2016-2017 Chukong Technologies Inc.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "audio/apple/AudioDecoderAppleBuff.h"
#include "audio/apple/AudioMacros.h"
#include "platform/CCFileUtils.h"

#import <Foundation/Foundation.h>

#define LOG_TAG "AudioDecoderAppleBuff"

namespace cocos2d { namespace experimental {
    AudioDecoderAppleBuff::AudioDecoderAppleBuff()
    {
    }

    AudioDecoderAppleBuff::~AudioDecoderAppleBuff()
    {
        //must call father call no release _extRef
        close();
    }

    bool AudioDecoderAppleBuff::open(const char* path)
    {
        m_TotalData = FileUtils::getInstance()->getDataFromFile(path);
        bool ret = false;
        CFURLRef fileURL = nil;
        do
        {
            BREAK_IF_ERR_LOG(path == nullptr || strlen(path) == 0, "Invalid path!");
            
            NSString *fileFullPath = [[NSString alloc] initWithCString:path encoding:NSUTF8StringEncoding];
            fileURL = (CFURLRef)[[NSURL alloc] initFileURLWithPath:fileFullPath];
            [fileFullPath release];
            BREAK_IF_ERR_LOG(fileURL == nil, "Converting path to CFURLRef failed!");
            
            AudioFileTypeID typeID = 0;
            AudioFileID audioFileID;
            OSStatus status = AudioFileOpenWithCallbacks(this, [](void * inClientData, SInt64 inPosition, UInt32 requestCount, void* buffer, UInt32* actualCount)->OSStatus{
                AudioDecoderAppleBuff* pContext = (AudioDecoderAppleBuff*)inClientData;
                if(inPosition > pContext->m_TotalData.getSize())
                    return kUnknownType;
                else if(inPosition == pContext->m_TotalData.getSize()){
                    *actualCount = 0;
                    return noErr;
                }
                if(inPosition + requestCount > pContext->m_TotalData.getSize()){
                    *actualCount = pContext->m_TotalData.getSize() - inPosition;
                }
                else{
                    *actualCount = requestCount;
                }
                memcpy(buffer, pContext->m_TotalData.getBytes() + inPosition, *actualCount);
                return noErr;
            }, nullptr, [](void* inClientData)->SInt64{
                AudioDecoderAppleBuff* pContext = (AudioDecoderAppleBuff*)inClientData;
                return pContext->m_TotalData.getSize();
            }, nullptr, typeID, &audioFileID);
            
            BREAK_IF_ERR_LOG(status != noErr, "ExtAudioFileOpenURL FAILED, Error = %ld", (long)ret);
            status = ExtAudioFileWrapAudioFileID(audioFileID, false, &_extRef);
            BREAK_IF_ERR_LOG(status != noErr, "ExtAudioFileOpenURL FAILED, Error = %ld", (long)ret);
            
            AudioStreamBasicDescription	fileFormat;
            UInt32 propertySize = sizeof(fileFormat);
            
            // Get the audio data format
            ret = ExtAudioFileGetProperty(_extRef, kExtAudioFileProperty_FileDataFormat, &propertySize, &fileFormat);
            BREAK_IF_ERR_LOG(status != noErr, "ExtAudioFileGetProperty(kExtAudioFileProperty_FileDataFormat) FAILED, Error = %ld", (long)ret);
            BREAK_IF_ERR_LOG(fileFormat.mChannelsPerFrame > 2, "Unsupported Format, channel count is greater than stereo!");
            
            // Set the client format to 16 bit signed integer (native-endian) data
            // Maintain the channel count and sample rate of the original source format
            _outputFormat.mSampleRate = fileFormat.mSampleRate;
            _outputFormat.mChannelsPerFrame = fileFormat.mChannelsPerFrame;
            _outputFormat.mFormatID = kAudioFormatLinearPCM;
            _outputFormat.mFramesPerPacket = 1;
            _outputFormat.mBitsPerChannel = 16;
            _outputFormat.mFormatFlags = kAudioFormatFlagsNativeEndian | kAudioFormatFlagIsPacked | kAudioFormatFlagIsSignedInteger;
            
            _sampleRate = _outputFormat.mSampleRate;
            _channelCount = _outputFormat.mChannelsPerFrame;
            _bytesPerFrame = 2 * _outputFormat.mChannelsPerFrame;
            
            _outputFormat.mBytesPerPacket = _bytesPerFrame;
            _outputFormat.mBytesPerFrame = _bytesPerFrame;
            
            ret = ExtAudioFileSetProperty(_extRef, kExtAudioFileProperty_ClientDataFormat, sizeof(_outputFormat), &_outputFormat);
            BREAK_IF_ERR_LOG(status != noErr, "ExtAudioFileSetProperty FAILED, Error = %ld", (long)ret);
            
            // Get the total frame count
            SInt64 totalFrames = 0;
            propertySize = sizeof(totalFrames);
            ret = ExtAudioFileGetProperty(_extRef, kExtAudioFileProperty_FileLengthFrames, &propertySize, &totalFrames);
            BREAK_IF_ERR_LOG(status != noErr, "ExtAudioFileGetProperty(kExtAudioFileProperty_FileLengthFrames) FAILED, Error = %ld", (long)ret);
            BREAK_IF_ERR_LOG(totalFrames <= 0, "Total frames is 0, it's an invalid audio file: %s", path);
            _totalFrames = static_cast<uint32_t>(totalFrames);
            _isOpened = true;
            
            ret = true;
        } while (false);
        
        if (fileURL != nil)
            CFRelease(fileURL);
        
        if (!ret)
        {
            close();
        }
        
        return ret;
    }
    /**
     * use getdatafromfile to read all data
    */
    bool AudioDecoderAppleBuff::IsBufferMode() const
    {
        return true;
    }
}} // namespace cocos2d { namespace experimental {
