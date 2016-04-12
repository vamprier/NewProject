#pragma once

#include "BaseData.h"
#include "GraphData.h"

// CGraphView ��ͼ

class CGraphView : public CView
{
	DECLARE_DYNCREATE(CGraphView)

protected:
	CGraphView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CGraphView();

public:
	CBaseData* m_Graph;

public:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


