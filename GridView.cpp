// GridView.cpp : ʵ���ļ�
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


// CGridView ��ͼ

void CGridView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: �ڴ���ӻ��ƴ���
}


// CGridView ���

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


// CGridView ��Ϣ�������
