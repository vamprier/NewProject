
// NewProjectView.h : CNewProjectView ��Ľӿ�
//

#pragma once


class CNewProjectView : public CView
{
protected: // �������л�����
	CNewProjectView();
	DECLARE_DYNCREATE(CNewProjectView)

// ����
public:
	CNewProjectDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CNewProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // NewProjectView.cpp �еĵ��԰汾
inline CNewProjectDoc* CNewProjectView::GetDocument() const
   { return reinterpret_cast<CNewProjectDoc*>(m_pDocument); }
#endif

