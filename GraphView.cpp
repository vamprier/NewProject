// GraphView.cpp : ʵ���ļ�
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


// CGraphView ��ͼ

void CGraphView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: �ڴ���ӻ��ƴ���

}


// CGraphView ���

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


// CGraphView ��Ϣ�������


int CGraphView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	CMainFrame* wnd = (CMainFrame*)AfxGetMainWnd();
	m_Graph = wnd->m_Data;
	return 0;
}
