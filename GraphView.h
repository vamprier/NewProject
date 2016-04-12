#pragma once

#include "BaseData.h"
#include "GraphData.h"

// CGraphView 视图

class CGraphView : public CView
{
	DECLARE_DYNCREATE(CGraphView)

protected:
	CGraphView();           // 动态创建所使用的受保护的构造函数
	virtual ~CGraphView();

public:
	CBaseData* m_Graph;

public:
	virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图
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


