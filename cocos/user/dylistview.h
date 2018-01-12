#ifndef COCOS_DYLISTVIEWCOMM
#define COCOS_DYLISTVIEWCOMM

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class CC_GUI_DLL CDyListViewLoadLayout : public cocos2d::ui::Widget
{
public:
	CDyListViewLoadLayout();
	virtual ~CDyListViewLoadLayout();

	CREATE_FUNC(CDyListViewLoadLayout);

	//设置dirty函数，下一帧如果已经初始化就重新初始化
	void SetDirty(bool bDirty){ m_bDirty = bDirty; }
	//初始化函数
	void InitLayout(cocos2d::ui::ListView* pList);
	//不可见
	void NoInView();
	//选中
	void SelectItem(cocos2d::ui::ListView* pList, cocos2d::Touch* pTouch);
	//非选中
	void UnSelectItem(cocos2d::ui::ListView* pList, cocos2d::Touch* pTouch);
	//绑定
	void bindCreateFunc(const std::function<cocos2d::Node*(CDyListViewLoadLayout* pLayout, cocos2d::Node* pNode)>& func){
		m_createFunc = func;
	}
	//绑定select状态
	void BindSelectChangeItemCallback(const std::function<void(cocos2d::Node*, cocos2d::Touch*, bool)>& funcSelectChangeItem){
		m_pSelectChangeItemCallback = funcSelectChangeItem;
	}

	//获取创建的节点
	cocos2d::Node* GetCreateNode(){ return m_pCreateNode; }
protected:
	virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4 &parentTransform, uint32_t parentFlags);
	void DealWithDirty();
protected:
	bool															m_bDirty;
	cocos2d::Node*													m_pCreateNode;
	std::function<cocos2d::Node*(CDyListViewLoadLayout*, cocos2d::Node*)>		m_createFunc;
	std::function<void(cocos2d::Node*, cocos2d::Touch*, bool)>		m_pSelectChangeItemCallback;
};

class CDyListView : public cocos2d::ui::ListView{
public:
	CDyListView();
	virtual ~CDyListView();

	CREATE_FUNC(CDyListView);
public:
	//加入数据
	void ReLoadListViewItems(const std::function<void(cocos2d::ui::ListView*)>& func);
	//删除listview的某一个
	void DeleteListViewRow(cocos2d::Node* pRow);
	//提供函数删除listview的所有数据
	void RemoveDyListViewItems();
	//增加处理函数选中改变的处理函数
	void BindSelectItemChangeFunc(const std::function<void(cocos2d::ui::ListView* pList, ssize_t sIndex, cocos2d::Touch* pTouch)>& func);
	void BindMessageCallbackFunc(const std::function<void(cocos2d::ui::ListView* pList, int, int)>& func);
	//提供自己更新的函数
	void NextFPSReCalcShowView();
	//获取实际内部大小
	float GetRealInnerHeight();
	//移动原来的位置
	void ChangeItemPosition(cocos2d::ui::Widget* pChild, int nPos);
	//设置是否固定位置
	void SetInnerDyFixLocation(bool bFix);
	//设置选中行
	void SetCurSelectItem(cocos2d::ui::Widget* pChild);
	void SetCurSelectIndex(int nIndex);
protected:
	virtual void onEnter();
	//listview加入到动态创建实现的函数
	void AddListViewToDyCreateList();
	//滚动计算list的初始化layout
	void CalcDyListViewLayout();
	//延迟计算显示位置
	void DelayCalcShowItems(float fDelay);
	void DelaySendMessageScrollTop(float fDelay);
	void DelaySendMessageScrollBottom(float fDelay);
protected:
	virtual void interceptTouchEvent(TouchEventType event, cocos2d::ui::Widget* sender, cocos2d::Touch *touch) override;
	//virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unusedEvent) override;
	//virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unusedEvent) override;
	//virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unusedEvent) override;
protected:
	//加入下一帧删除的队列
	template<class T>
	void ClearItemList(cocos2d::Vector<T*>& vtItemList){
		for (const auto &obj : vtItemList){
			m_vtRetainChild.pushBack(obj);
		}
		//下一帧清除
		scheduleOnce(CC_SCHEDULE_SELECTOR(CDyListView::OnTimerToClearRetainChild), 0.0f);
	}
	void ClearItem(cocos2d::Node* pNode){
		m_vtRetainChild.pushBack(pNode);
		//下一帧清除
		scheduleOnce(CC_SCHEDULE_SELECTOR(CDyListView::OnTimerToClearRetainChild), 0.0f);
	}
	void OnTimerToClearRetainChild(float fDelay){
		m_vtRetainChild.clear();
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////
protected:
	std::function<void(cocos2d::ui::ListView* pList, ssize_t sIndex, cocos2d::Touch* pTouch)>	m_funcSelectChange;
	std::function<void(cocos2d::ui::ListView* pList, int, int)>									m_funcMessageCallback;
	//下一帧清除的数据
	cocos2d::Vector<cocos2d::Node*>				m_vtRetainChild;
	cocos2d::ValueMapIntKey						m_mapRevertData;
};

#endif