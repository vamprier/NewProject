
// NewProjectView.h : CNewProjectView 类的接口
//

#pragma once


class CNewProjectView : public CView
{
protected: // 仅从序列化创建
	CNewProjectView();
	DECLARE_DYNCREATE(CNewProjectView)

// 特性
public:
	CNewProjectDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CNewProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // NewProjectView.cpp 中的调试版本
inline CNewProjectDoc* CNewProjectView::GetDocument() const
   { return reinterpret_cast<CNewProjectDoc*>(m_pDocument); }
#endif

