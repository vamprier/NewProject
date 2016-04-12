// GraphView.cpp : 实现文件
//

#include "stdafx.h"
#include "NewProject.h"
#include "GraphView.h"
#include "MainFrm.h"


// CGraphView

IMPLEMENT_DYNCREATE(CGraphView, CView)

CGraphView::CGraphView()
{

}

CGraphView::~CGraphView()
{
}

BEGIN_MESSAGE_MAP(CGraphView, CView)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CGraphView 绘图

void CGraphView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码

}


// CGraphView 诊断

#ifdef _DEBUG
void CGraphView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CGraphView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CGraphView 消息处理程序


int CGraphView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	CMainFrame* wnd = (CMainFrame*)AfxGetMainWnd();
	m_Graph = wnd->m_Data;
	return 0;
}
