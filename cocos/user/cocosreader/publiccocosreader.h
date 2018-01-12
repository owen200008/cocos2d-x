#ifndef GLOBALPUBLICCOCOSREADER_H
#define GLOBALPUBLICCOCOSREADER_H

#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/CSParseBinary_generated.h"
#include "cocostudio/ActionTimeline/CCActionTimeline.h"
#include "cocostudio/CCComExtensionData.h"

#include "../external/tinyxml2/tinyxml2.h"
#include "flatbuffers/flatbuffers.h"
#include "ui/UILayoutComponent.h"

USING_NS_CC;
using namespace flatbuffers;

template<class TA, class TB>
class CocosPublicReader : public cocostudio::NodeReader
{
public:
	CocosPublicReader(){
	}
	virtual ~CocosPublicReader(){
	}

	static TA* getInstance(){
		if (!m_instanceReader){
			m_instanceReader = new (std::nothrow) TA();
		}
		return m_instanceReader;
	}
	/** @deprecated Use method destroyInstance() instead */
	CC_DEPRECATED_ATTRIBUTE static void purge(){
		CC_SAFE_DELETE(m_instanceReader);
	}
	static void destroyInstance(){
		CC_SAFE_DELETE(m_instanceReader);
	}

	flatbuffers::Offset<flatbuffers::Table> createOptionsWithFlatBuffers(const tinyxml2::XMLElement* objectData,
		flatbuffers::FlatBufferBuilder* builder){
		return NodeReader::createOptionsWithFlatBuffers(objectData, builder);
	}
	void setPropsWithFlatBuffers(cocos2d::Node* node, const flatbuffers::Table* nodeOptions){
		NodeReader::setPropsWithFlatBuffers(node, nodeOptions);
	}
	void setLayoutComponentPropsWithFlatBuffers(cocos2d::Node* node, const flatbuffers::Table* nodeOptions){
		NodeReader::setLayoutComponentPropsWithFlatBuffers(node, nodeOptions);
	}
	cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions){
		return createNodeSpecialFlagBuffers(nodeOptions);
	}
	virtual cocos2d::Node* createNodeSpecialFlagBuffers(const flatbuffers::Table* nodeOptions){
		TB* node = TB::create();
		setPropsWithFlatBuffers(node, nodeOptions);
		return node;
	}
public:
	static TA*	m_instanceReader;
};

#define DECLARE_XMQXZREADER_HEADER_DEFINE(A, B) \
class A : public CocosPublicReader<A, B> \
{\
	DECLARE_CLASS_NODE_READER_INFO \
};

#define IMPLEMENT_XMQXZREADER_INFO_DEFINE(A, B) \
	IMPLEMENT_CLASS_NODE_READER_INFO(A)\
	template<> A* CocosPublicReader<A, B>::m_instanceReader = nullptr;

#endif