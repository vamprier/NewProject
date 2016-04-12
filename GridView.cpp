// GridView.cpp : 实现文件
//

#include "stdafx.h"
#include "NewProject.h"
#include "GridView.h"


// CGridView

IMPLEMENT_DYNCREATE(CGridView, CView)

CGridView::CGridView()
{

}

CGridView::~CGridView()
{
}

BEGIN_MESSAGE_MAP(CGridView, CView)
END_MESSAGE_MAP()


// CGridView 绘图

void CGridView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码
}


// CGridView 诊断

#ifdef _DEBUG
void CGridView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CGridView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CGridView 消息处理程序
