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

	//����dirty��������һ֡����Ѿ���ʼ�������³�ʼ��
	void SetDirty(bool bDirty){ m_bDirty = bDirty; }
	//��ʼ������
	void InitLayout(cocos2d::ui::ListView* pList);
	//���ɼ�
	void NoInView();
	//ѡ��
	void SelectItem(cocos2d::ui::ListView* pList, cocos2d::Touch* pTouch);
	//��ѡ��
	void UnSelectItem(cocos2d::ui::ListView* pList, cocos2d::Touch* pTouch);
	//��
	void bindCreateFunc(const std::function<cocos2d::Node*(CDyListViewLoadLayout* pLayout, cocos2d::Node* pNode)>& func){
		m_createFunc = func;
	}
	//��select״̬
	void BindSelectChangeItemCallback(const std::function<void(cocos2d::Node*, cocos2d::Touch*, bool)>& funcSelectChangeItem){
		m_pSelectChangeItemCallback = funcSelectChangeItem;
	}

	//��ȡ�����Ľڵ�
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
	//��������
	void ReLoadListViewItems(const std::function<void(cocos2d::ui::ListView*)>& func);
	//ɾ��listview��ĳһ��
	void DeleteListViewRow(cocos2d::Node* pRow);
	//�ṩ����ɾ��listview����������
	void RemoveDyListViewItems();
	//���Ӵ�����ѡ�иı�Ĵ�����
	void BindSelectItemChangeFunc(const std::function<void(cocos2d::ui::ListView* pList, ssize_t sIndex, cocos2d::Touch* pTouch)>& func);
	void BindMessageCallbackFunc(const std::function<void(cocos2d::ui::ListView* pList, int, int)>& func);
	//�ṩ�Լ����µĺ���
	void NextFPSReCalcShowView();
	//��ȡʵ���ڲ���С
	float GetRealInnerHeight();
	//�ƶ�ԭ����λ��
	void ChangeItemPosition(cocos2d::ui::Widget* pChild, int nPos);
	//�����Ƿ�̶�λ��
	void SetInnerDyFixLocation(bool bFix);
	//����ѡ����
	void SetCurSelectItem(cocos2d::ui::Widget* pChild);
	void SetCurSelectIndex(int nIndex);
protected:
	virtual void onEnter();
	//listview���뵽��̬����ʵ�ֵĺ���
	void AddListViewToDyCreateList();
	//��������list�ĳ�ʼ��layout
	void CalcDyListViewLayout();
	//�ӳټ�����ʾλ��
	void DelayCalcShowItems(float fDelay);
	void DelaySendMessageScrollTop(float fDelay);
	void DelaySendMessageScrollBottom(float fDelay);
protected:
	virtual void interceptTouchEvent(TouchEventType event, cocos2d::ui::Widget* sender, cocos2d::Touch *touch) override;
	//virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unusedEvent) override;
	//virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unusedEvent) override;
	//virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unusedEvent) override;
protected:
	//������һ֡ɾ���Ķ���
	template<class T>
	void ClearItemList(cocos2d::Vector<T*>& vtItemList){
		for (const auto &obj : vtItemList){
			m_vtRetainChild.pushBack(obj);
		}
		//��һ֡���
		scheduleOnce(CC_SCHEDULE_SELECTOR(CDyListView::OnTimerToClearRetainChild), 0.0f);
	}
	void ClearItem(cocos2d::Node* pNode){
		m_vtRetainChild.pushBack(pNode);
		//��һ֡���
		scheduleOnce(CC_SCHEDULE_SELECTOR(CDyListView::OnTimerToClearRetainChild), 0.0f);
	}
	void OnTimerToClearRetainChild(float fDelay){
		m_vtRetainChild.clear();
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////
protected:
	std::function<void(cocos2d::ui::ListView* pList, ssize_t sIndex, cocos2d::Touch* pTouch)>	m_funcSelectChange;
	std::function<void(cocos2d::ui::ListView* pList, int, int)>									m_funcMessageCallback;
	//��һ֡���������
	cocos2d::Vector<cocos2d::Node*>				m_vtRetainChild;
	cocos2d::ValueMapIntKey						m_mapRevertData;
};

#endif