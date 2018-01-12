#include "cocosrichtextReader.h"
#include "tinyxml2/tinyxml2.h"
#include "flatbuffers/flatbuffers.h"
#include "cocostudio/CSParseBinary_generated.h"
#include "cocosrichtextOptions_generated.h"
#include "cocosrichtext.h"

USING_NS_CC;
using namespace ui;
using namespace flatbuffers;

static CocosRichTextReader* instanceCWRatioImageReader = nullptr;

IMPLEMENT_CLASS_NODE_READER_INFO(CocosRichTextReader)

CocosRichTextReader::CocosRichTextReader()
{
	
}

CocosRichTextReader::~CocosRichTextReader()
{

}

CocosRichTextReader* CocosRichTextReader::getInstance()
{
	if (!instanceCWRatioImageReader)
	{
		instanceCWRatioImageReader = new (std::nothrow) CocosRichTextReader();
	}
	return instanceCWRatioImageReader;
}

void CocosRichTextReader::destroyInstance()
{
	CC_SAFE_DELETE(instanceCWRatioImageReader);
}

Offset<Table> CocosRichTextReader::createOptionsWithFlatBuffers(const tinyxml2::XMLElement *objectData,
	flatbuffers::FlatBufferBuilder *builder){
	auto temp = NodeReader::getInstance()->createOptionsWithFlatBuffers(objectData, builder);
	auto nodeOptions = *(Offset<WidgetOptions>*)(&temp);

	float fNewWidth = 0.0f;
	float fNewHeight = 0.0f;
	std::string strDrawColor;
	std::string strFontName;
	int nFontSize = 20;
	std::string strText;
	bool xcenter = 0;
	bool ycenter = 0;
	bool clkBySelf = 0;
	int nLineSprite = 0;
	const tinyxml2::XMLAttribute* attribute = objectData->FirstAttribute();
	while (attribute){
		std::string attriname = attribute->Name();
		std::string value = attribute->Value();

		if (attriname == "NewWidth"){
			fNewWidth = atof(value.c_str());
		}
		else if (attriname == "NewHeight"){
			fNewHeight = atof(value.c_str());
		}
		else if (attriname == "drawcolor"){
			strDrawColor = value;
		}
		else if (attriname == "m_strFontFile"){
			strFontName = value;
		}
		else if (attriname == "FontSize"){
			nFontSize = atoi(value.c_str());
		}
		else if (attriname == "LabelText"){
			strText = value.c_str();
		}
		else if (attriname == "XCenter"){
			xcenter = (value == "True") ? true : false;
		}
		else if (attriname == "YCenter"){
			ycenter = (value == "True") ? true : false;
		}
		else if (attriname == "ClkBySelf"){
			clkBySelf = (value == "True") ? true : false;
		}
		else if (attriname == "LineSprite"){
			nLineSprite = atoi(value.c_str());
		}
		
		attribute = attribute->Next();
	}

	auto options = flatbuffers::CreatecocosrichtextOptions(*builder,
		nodeOptions,
		clkBySelf, fNewWidth, fNewHeight,
		builder->CreateString(strDrawColor), builder->CreateString(strFontName), 
		nFontSize, builder->CreateString(strText),
		xcenter, ycenter, nLineSprite);

	return *(Offset<Table>*)(&options);
}

void CocosRichTextReader::setPropsWithFlatBuffers(cocos2d::Node *node,
	const flatbuffers::Table* singleNodeOptions){
	auto options = (flatbuffers::cocosrichtextOptions*)singleNodeOptions;
	NodeReader::setPropsWithFlatBuffers(node, (Table*)options->nodeOptions());

	CCocosRichTextNodeForCocos* real = static_cast<CCocosRichTextNodeForCocos*>(node);

	const char* pText = options->LabelText()->c_str();
	if (pText){
		real->SetDataText(pText);
	}
	const char* pFontName = options->m_strFontFile()->c_str();
	if (pFontName){
		real->SetFontName(pFontName);
	}
	const char* pTextColor = options->drawcolor()->c_str();
	if (pTextColor){
		real->SetFontColor(pTextColor);
	}
	real->SetFontSize(options->FontSize());
	real->SetBHCenter(options->XCenter());
	real->SetBVCenter(options->YCenter());

	real->SetTouchEnable(options->ClkBySelf());
	real->SetLineAddMinY(options->LineSprite());
}

Node* CocosRichTextReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions){
	CCocosRichTextNodeForCocos* node = CCocosRichTextNodeForCocos::create();
	// self
	setPropsWithFlatBuffers(node, nodeOptions);

	return node;
}


