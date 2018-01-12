

#include "dylistviewReader.h"
#include "tinyxml2/tinyxml2.h"
#include "flatbuffers/flatbuffers.h"
#include "cocostudio/CSParseBinary_generated.h"
#include "dylistviewOptions_generated.h"
#include "dylistview.h"

USING_NS_CC;
using namespace ui;
using namespace flatbuffers;

static DyListViewReader* instanceCWRatioImageReader = nullptr;

IMPLEMENT_CLASS_NODE_READER_INFO(DyListViewReader)

DyListViewReader::DyListViewReader()
{
	
}

DyListViewReader::~DyListViewReader()
{

}

DyListViewReader* DyListViewReader::getInstance()
{
	if (!instanceCWRatioImageReader)
	{
		instanceCWRatioImageReader = new (std::nothrow) DyListViewReader();
	}
	return instanceCWRatioImageReader;
}

void DyListViewReader::destroyInstance()
{
	CC_SAFE_DELETE(instanceCWRatioImageReader);
}

Offset<Table> DyListViewReader::createOptionsWithFlatBuffers(const tinyxml2::XMLElement *objectData,
	flatbuffers::FlatBufferBuilder *builder)
{
	return ListViewReader::getInstance()->createOptionsWithFlatBuffers(objectData, builder);
}

void DyListViewReader::setPropsWithFlatBuffers(cocos2d::Node *node,
	const flatbuffers::Table* singleNodeOptions)
{
	auto options = (flatbuffers::dylistviewOptions*)singleNodeOptions;
	
	ListViewReader::setPropsWithFlatBuffers(node, (const flatbuffers::Table*)options);
}

Node* DyListViewReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
	CDyListView* node = CDyListView::create();
	// self
	setPropsWithFlatBuffers(node, nodeOptions);

	return node;
}


