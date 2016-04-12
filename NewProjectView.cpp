
// NewProjectView.cpp : CNewProjectView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CNewProjectView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CNewProjectView 构造/析构

CNewProjectView::CNewProjectView()
{
	// TODO: 在此处添加构造代码

}

CNewProjectView::~CNewProjectView()
{
}

BOOL CNewProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CNewProjectView 绘制

void CNewProjectView::OnDraw(CDC* /*pDC*/)
{
	CNewProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CNewProjectView 打印


void CNewProjectView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CNewProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CNewProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CNewProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CNewProjectView 诊断

#ifdef _DEBUG
void CNewProjectView::AssertValid() const
{
	CView::AssertValid();
}

void CNewProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNewProjectDoc* CNewProjectView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNewProjectDoc)));
	return (CNewProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// CNewProjectView 消息处理程序


void CNewProjectView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	// TODO: 在此添加专用代码和/或调用基类
	GetDocument()->SetTitle(_T("起始页"));
}
