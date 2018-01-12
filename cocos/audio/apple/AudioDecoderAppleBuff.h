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

#pragma once

#include <stdint.h>
#import <AudioToolbox/ExtendedAudioFile.h>
#include "AudioDecoderApple.h"
#include "base/CCData.h"

namespace cocos2d { namespace experimental {

/**
 * @brief The class for decoding compressed audio file to PCM buffer.
 */
class AudioDecoderAppleBuff : public AudioDecoderApple
{
public:
    AudioDecoderAppleBuff();
    virtual ~AudioDecoderAppleBuff();

    /**
     * @brief Opens an audio file specified by a file path.
     * @return true if succeed, otherwise false.
     */
    virtual bool open(const char* path) override;

	/**
     * use getdatafromfile to read all data
    */
    virtual bool IsBufferMode() const override;
private:
    Data m_TotalData;
};

}} // namespace cocos2d { namespace experimental {
