
// NewProject.h : NewProject Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CNewProjectApp:
// �йش����ʵ�֣������ NewProject.cpp
//

class CNewProjectApp : public CWinAppEx
{
public:
	CNewProjectApp();
public:
	CMultiDocTemplate* pDocTemplate;
	CMultiDocTemplate* pGridTemplate;
	CMultiDocTemplate* pGraphTemplate;
	CView* GetImageView(CDocTemplate* templ,LPTSTR str);
	CView* GetGridView(CDocTemplate* templ,LPTSTR str);

	void OnFileNew();

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CNewProjectApp theApp;
