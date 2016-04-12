#pragma once

#include "resource.h"
// CExportStudentScore 对话框

class CExportStudentScore : public CDialogEx
{
	DECLARE_DYNAMIC(CExportStudentScore)

public:
	CExportStudentScore(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CExportStudentScore();

// 对话框数据
	enum { IDD = IDD_DIALOG_STUDENTSCORE };
public:
	CString fpath;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_FilePath;
	afx_msg void OnBnClickedButtonOpen();
};
