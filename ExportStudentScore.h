#pragma once

#include "resource.h"
// CExportStudentScore �Ի���

class CExportStudentScore : public CDialogEx
{
	DECLARE_DYNAMIC(CExportStudentScore)

public:
	CExportStudentScore(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CExportStudentScore();

// �Ի�������
	enum { IDD = IDD_DIALOG_STUDENTSCORE };
public:
	CString fpath;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_FilePath;
	afx_msg void OnBnClickedButtonOpen();
};
