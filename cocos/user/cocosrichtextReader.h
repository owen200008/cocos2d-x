#pragma once

#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"
#include "cocostudio/CocosStudioExport.h"

using namespace cocostudio;

class CC_STUDIO_DLL CocosRichTextReader : public NodeReader
{
    DECLARE_CLASS_NODE_READER_INFO
        
public:
	CocosRichTextReader();
	virtual ~CocosRichTextReader();
        
	static CocosRichTextReader* getInstance();

    static void destroyInstance();
        
	flatbuffers::Offset<flatbuffers::Table> createOptionsWithFlatBuffers(const tinyxml2::XMLElement* objectData,
		flatbuffers::FlatBufferBuilder* builder);
	void setPropsWithFlatBuffers(cocos2d::Node* node, const flatbuffers::Table* singleNodeOptions);

    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* textOptions);

};

