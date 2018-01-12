#include "dylistview.h"
#include "cocostudio/CocoStudio.h"
//#include "CocosNodeCreateWithLuaReader.h"

using namespace cocos2d;

void CDyListViewLoadLayout::visit(cocos2d::Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
	DealWithDirty();
	cocos2d::ui::Widget::visit(renderer, parentTransform, parentFlags);
}

void CDyListViewLoadLayout::DealWithDirty()
{
	if (m_bDirty)
	{
		if (m_pCreateNode)
		{
			m_createFunc(this, m_pCreateNode);
			m_pCreateNode->setCameraMask(getCameraMask());
			setContentSize(m_pCreateNode->getContentSize());
			cocos2d::ui::ListView* pList = dynamic_cast<cocos2d::ui::ListView*>(getParent());
			if (pList)
			{
				pList->requestDoLayout();
			}
		}
		m_bDirty = false;
	}
}

CDyListViewLoadLayout::CDyListViewLoadLayout()
{
	m_pCreateNode = NULL;
	m_bDirty = false;
}

CDyListViewLoadLayout::~CDyListViewLoadLayout()
{

}
void CDyListViewLoadLayout::InitLayout(cocos2d::ui::ListView* pList)
{
	if (m_pCreateNode)
	{
		DealWithDirty();
		if (!m_pCreateNode->isVisible())
		{
			m_pCreateNode->resume();
			m_pCreateNode->setVisible(true);
		}
		return;
	}
    Node* pChild = getChildByTag(1);
    if (pChild){
        m_pCreateNode = pChild;
    }
    else{
        m_pCreateNode = m_createFunc(this, nullptr);
        setContentSize(m_pCreateNode->getContentSize());
        m_pCreateNode->setCameraMask(getCameraMask());
        addChild(m_pCreateNode);
        //大小改变要求listview重新排列
        pList->requestDoLayout();
    }
}

void CDyListViewLoadLayout::NoInView()
{
	if (m_pCreateNode)
	{
		//如果已经创建，但是没在显示区
		if (m_pCreateNode->isVisible())
		{
			m_pCreateNode->pause();
			m_pCreateNode->setVisible(false);
		}
	}
}
//选中
void CDyListViewLoadLayout::SelectItem(cocos2d::ui::ListView* pList, cocos2d::Touch* pTouch)
{
	InitLayout(pList);
	if(m_pSelectChangeItemCallback)
		m_pSelectChangeItemCallback(m_pCreateNode, pTouch, true);
}
//非选中
void CDyListViewLoadLayout::UnSelectItem(cocos2d::ui::ListView* pList, cocos2d::Touch* pTouch)
{
	InitLayout(pList);
	if (m_pSelectChangeItemCallback)
		m_pSelectChangeItemCallback(m_pCreateNode, pTouch, false);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CDyListView::CDyListView()
{

}

CDyListView::~CDyListView()
{

}

float CDyListView::GetRealInnerHeight()
{
	switch (_direction)
	{
	case Direction::VERTICAL:
	{
		float totalHeight = 0;
		size_t length = _items.size();
		if (length > 0)
		{
			totalHeight = (length - 1) * _itemsMargin;
		}
		for (auto& item : _items)
		{
			totalHeight += item->getContentSize().height;
		}
		return totalHeight;
	}
	case Direction::HORIZONTAL:
	{
		return _contentSize.height;
	}
	default:
		break;
	}
	return 0;
}
//移动原来的位置
void CDyListView::ChangeItemPosition(cocos2d::ui::Widget* pChild, int nPos)
{
	Vector<Widget*>& vtItems = getItems();
	if (nPos >= vtItems.size())
	{
		//去掉自己
		nPos = vtItems.size() - 1;
		if (nPos < 0)
			nPos = 0;
	}
	ssize_t nIndex = getIndex(pChild);
	if (nIndex >= 0 && nIndex != nPos)
	{
		pChild->retain();
		removeChild(pChild, false);
		requestDoLayout();
		insertCustomItem(pChild, nPos);
		pChild->release();
	}
}
//设置是否固定位置
void CDyListView::SetInnerDyFixLocation(bool bFix)
{
	SetFixInnerPosition(bFix);
}
//设置选中行
void CDyListView::SetCurSelectItem(cocos2d::ui::Widget* pChild)
{
	int nIndex = getIndex(pChild);
	if (nIndex < 0)
		return;
	SetCurSelectIndex(nIndex);
	
}
void CDyListView::SetCurSelectIndex(int nIndex)
{
	int nCurIndex = getCurSelectedIndex();
	if (nCurIndex == nIndex)
		return;
	cocos2d::ui::Widget* pChild = getItem(nIndex);
	if (pChild)
	{
		Touch touch;
		selectedItemEvent(TouchEventType::BEGAN, pChild, &touch);
		selectedItemEvent(TouchEventType::ENDED, pChild, &touch);
	}
}

void CDyListView::onEnter()
{
	cocos2d::ui::ListView::onEnter();

	AddListViewToDyCreateList();
}

void CDyListView::DelayCalcShowItems(float fDelay)
{
	CalcDyListViewLayout();
}
void CDyListView::DelaySendMessageScrollTop(float fDelay)
{
	
}
void CDyListView::DelaySendMessageScrollBottom(float fDelay)
{

}

void CDyListView::AddListViewToDyCreateList()
{
	//默认插入不改变位置
	SetFixInnerPosition(true);
	cocos2d::ui::ListView::ccScrollViewCallback callbackScroll = [this](Ref* pObject, cocos2d::ui::ScrollView::EventType eventScroll) -> void
	{
		switch (eventScroll)
		{
		case cocos2d::ui::ScrollView::EventType::CONTAINER_MOVED:
		{
			if (!isScheduled(schedule_selector(CDyListView::DelayCalcShowItems)))
			{
				//延迟计算10帧
				scheduleOnce(schedule_selector(CDyListView::DelayCalcShowItems), 0.1f);
			}
		}
		break;
		case cocos2d::ui::ScrollView::EventType::BOUNCE_TOP:
		{
			if (!isScheduled(schedule_selector(CDyListView::DelaySendMessageScrollTop)))
			{
				//延迟计算2s
				scheduleOnce(schedule_selector(CDyListView::DelaySendMessageScrollTop), 1.5f);
				if (m_funcMessageCallback)
				{
					m_funcMessageCallback(this, 0, int(cocos2d::ui::ScrollView::EventType::BOUNCE_TOP));
				}
			}
		}
		break;
		case cocos2d::ui::ScrollView::EventType::BOUNCE_BOTTOM:
		{
			if (!isScheduled(schedule_selector(CDyListView::DelaySendMessageScrollBottom)))
			{
				//延迟计算2s
				scheduleOnce(schedule_selector(CDyListView::DelaySendMessageScrollBottom), 1.5f);
				if (m_funcMessageCallback)
				{
					m_funcMessageCallback(this, 0, int(cocos2d::ui::ScrollView::EventType::BOUNCE_BOTTOM));
				}
			}
		}
		break;
		}
	};
	addEventListener(callbackScroll);

	cocos2d::ui::ListView::ccListViewCallback callbackListView = [this](Ref* pObject, cocos2d::ui::ListView::EventType eventListView, cocos2d::Touch* pTouch) -> void
	{
		switch (eventListView)
		{
		case cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_END:
		{
			//获取当前的选择
			ssize_t sIndex = getCurSelectedIndex();
			if (sIndex >= 0)
			{
				CDyListViewLoadLayout* pPropLayOut = static_cast<CDyListViewLoadLayout*>(getItem(sIndex));
				if (pPropLayOut)
				{
					pPropLayOut->UnSelectItem(this, pTouch);
				}
			}
		}
		break;
		case cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_CHANGE:
		{
			//获取当前的选择
			ssize_t sIndex = getCurSelectedIndex();
			if (sIndex >= 0)
			{
				CDyListViewLoadLayout* pPropLayOut = static_cast<CDyListViewLoadLayout*>(getItem(sIndex));
				if (pPropLayOut)
				{
					pPropLayOut->SelectItem(this, pTouch);
					if (m_funcSelectChange)
						m_funcSelectChange(this, sIndex, pTouch);
				}
			}
		}
		break;
		}
	};
	addEventListener(callbackListView);
}
//增加处理函数选中改变的处理函数
void CDyListView::BindSelectItemChangeFunc(const std::function<void(cocos2d::ui::ListView* pList, ssize_t sIndex, cocos2d::Touch* pTouch)>& func)
{
	m_funcSelectChange = func;
}
void CDyListView::BindMessageCallbackFunc(const std::function<void(cocos2d::ui::ListView* pList, int, int)>& func)
{
	m_funcMessageCallback = func;
}
//创建动态listview对象
void CDyListView::ReLoadListViewItems(const std::function<void(cocos2d::ui::ListView*)>& func)
{
	RemoveDyListViewItems();

	func(this);

	scheduleOnce(CC_SCHEDULE_SELECTOR(CDyListView::DelayCalcShowItems), 0.0f);
}

//提供函数删除listview的所有数据
void CDyListView::RemoveDyListViewItems()
{
	//先清空原来的数据
	cocos2d::Vector<cocos2d::ui::Widget*>& vtNewItems = getItems();
	ClearItemList(vtNewItems);
	removeAllItems();
}


//删除listview的某一个
void CDyListView::DeleteListViewRow(cocos2d::Node* pRow)
{
	CDyListViewLoadLayout* pLayOut = static_cast<CDyListViewLoadLayout*>(pRow->getParent());
	if (NULL == pLayOut)
	{
		pLayOut = dynamic_cast<CDyListViewLoadLayout*>(pRow);
	}
	if (NULL == pLayOut)
	{
		assert(0);
		return;
	}
	ClearItem(pRow);
	removeItem(getIndex(pLayOut));
}


#define LISTREVERTKEYINIT_BEGIN		5000000
#define LISTREVERTKEYINIT_END		5000001
//滚动计算list的初始化layout
void CDyListView::CalcDyListViewLayout()
{
	Widget* pWidGetFar = getBottommostItemInCurrentView();
	Widget* pWidGetNear = getTopmostItemInCurrentView();
	if (NULL == pWidGetFar || NULL == pWidGetNear)
		return;
	int nFarIndex = getIndex(pWidGetFar);
	int nNearIndex = getIndex(pWidGetNear);
	//默认多处理两个
	nFarIndex++;
	nNearIndex--;
	if (nNearIndex < 0)
		nNearIndex = 0;

	cocos2d::ValueMapIntKey& valueMapData = m_mapRevertData;
	Value& vNear = valueMapData[LISTREVERTKEYINIT_BEGIN];
	Value& vFar = valueMapData[LISTREVERTKEYINIT_END];
	if (vNear.isNull() || vFar.isNull())
	{
		cocos2d::Vector<cocos2d::ui::Widget*>& vtItems = getItems();
		int nTotalSize = vtItems.size();
		for (int i = 0; i < nTotalSize; i++)
		{
			CDyListViewLoadLayout* pPropLayOut = static_cast<CDyListViewLoadLayout*>(vtItems.at(i));
			if (pPropLayOut)
			{
				if (i >= nNearIndex && i <= nFarIndex)
				{
					//可视区域
					pPropLayOut->InitLayout(this);
				}
				else
				{
					pPropLayOut->NoInView();
				}
			}
		}
	}
	else
	{
		cocos2d::Vector<cocos2d::ui::Widget*>& vtItems = getItems();
		int nTotalSize = vtItems.size();
		int nLastNear = vNear.asInt();
		int nLastFar = vFar.asInt();
		for (int i = nLastNear; i < nLastFar && i < nTotalSize; i++)
		{
			if (i < nNearIndex || i > nFarIndex)
			{
				CDyListViewLoadLayout* pPropLayOut = static_cast<CDyListViewLoadLayout*>(vtItems.at(i));
				if (pPropLayOut)
				{
					pPropLayOut->NoInView();
				}
			}
		}
		for (int j = nNearIndex; j <= nFarIndex && j < nTotalSize; j++)
		{
			CDyListViewLoadLayout* pPropLayOut = static_cast<CDyListViewLoadLayout*>(vtItems.at(j));
			if (pPropLayOut)
			{
				//可视区域
				pPropLayOut->InitLayout(this);
			}
		}
	}
	valueMapData[LISTREVERTKEYINIT_BEGIN] = nNearIndex;
	valueMapData[LISTREVERTKEYINIT_END] = nFarIndex;
}

//提供自己更新的函数
void CDyListView::NextFPSReCalcShowView()
{
	if (!isScheduled(CC_SCHEDULE_SELECTOR(CDyListView::DelayCalcShowItems)))
		scheduleOnce(CC_SCHEDULE_SELECTOR(CDyListView::DelayCalcShowItems), 0.0f);
}

void CDyListView::interceptTouchEvent(TouchEventType event, Widget* sender, Touch *touch)
{
	if (_propagateTouchEvents)
	{
		cocos2d::ui::Layout::interceptTouchEvent(event, sender, touch);
	}
	cocos2d::ui::ListView::interceptTouchEvent(event, sender, touch);
}
/*
bool CDyListView::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
{
	bool pass = cocos2d::ui::ListView::onTouchBegan(touch, unusedEvent);
	if (_hitted)
	{
		if (_propagateTouchEvents)
		{
			this->propagateTouchEvent(TouchEventType::BEGAN, this, touch);
		}
	}
	return pass;
}
void CDyListView::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
{
	cocos2d::ui::ListView::onTouchMoved(touch, unusedEvent);
	if (_propagateTouchEvents)
	{
		this->propagateTouchEvent(TouchEventType::MOVED, this, touch);
	}
}
void CDyListView::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
{
	cocos2d::ui::ListView::onTouchEnded(touch, unusedEvent);
	if (_propagateTouchEvents)
	{
		this->propagateTouchEvent(TouchEventType::ENDED, this, touch);
	}
}*/
