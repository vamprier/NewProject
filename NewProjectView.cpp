
// NewProjectView.cpp : CNewProjectView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "NewProject.h"
#endif

#include "NewProjectDoc.h"
#include "NewProjectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNewProjectView

IMPLEMENT_DYNCREATE(CNewProjectView, CView)

BEGIN_MESSAGE_MAP(CNewProjectView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CNewProjectView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CNewProjectView ����/����

CNewProjectView::CNewProjectView()
{
	// TODO: �ڴ˴���ӹ������

}

CNewProjectView::~CNewProjectView()
{
}

BOOL CNewProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CNewProjectView ����

void CNewProjectView::OnDraw(CDC* /*pDC*/)
{
	CNewProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CNewProjectView ��ӡ


void CNewProjectView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CNewProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CNewProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CNewProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CNewProjectView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CNewProjectView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CNewProjectView ���

#ifdef _DEBUG
void CNewProjectView::AssertValid() const
{
	CView::AssertValid();
}

void CNewProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNewProjectDoc* CNewProjectView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNewProjectDoc)));
	return (CNewProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// CNewProjectView ��Ϣ�������


void CNewProjectView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	// TODO: �ڴ����ר�ô����/����û���
	GetDocument()->SetTitle(_T("��ʼҳ"));
}
