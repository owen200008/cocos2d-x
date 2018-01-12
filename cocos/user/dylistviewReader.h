#pragma once

#include "cocostudio/WidgetReader/ListViewReader/ListViewReader.h"
#include "cocostudio/CocosStudioExport.h"

using namespace cocostudio;

class CC_STUDIO_DLL DyListViewReader : public ListViewReader
{
    DECLARE_CLASS_NODE_READER_INFO
        
public:
	DyListViewReader();
	virtual ~DyListViewReader();
        
	static DyListViewReader* getInstance();

    static void destroyInstance();
        
	flatbuffers::Offset<flatbuffers::Table> createOptionsWithFlatBuffers(const tinyxml2::XMLElement* objectData,
		flatbuffers::FlatBufferBuilder* builder);
	void setPropsWithFlatBuffers(cocos2d::Node* node, const flatbuffers::Table* singleNodeOptions);

    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* textOptions);

};

