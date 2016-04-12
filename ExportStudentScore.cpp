// ExportStudentScore.cpp : 实现文件
//

#include "stdafx.h"
#include "NewProject.h"
#include "ExportStudentScore.h"
#include "afxdialogex.h"

int CALLBACK AddFileFolder(HWND hwnd,UINT uMsg,LPARAM lParam,LPARAM lpData)  
{
	if(uMsg == BFFM_INITIALIZED)
	{  
		SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpData);
	}
	return 0;  
}

// CExportStudentScore 对话框

IMPLEMENT_DYNAMIC(CExportStudentScore, CDialogEx)

CExportStudentScore::CExportStudentScore(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExportStudentScore::IDD, pParent)
	, m_FilePath(_T(""))
{

}

CExportStudentScore::~CExportStudentScore()
{
}

void CExportStudentScore::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FILEPATH, m_FilePath);
}


BEGIN_MESSAGE_MAP(CExportStudentScore, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CExportStudentScore::OnBnClickedButtonOpen)
END_MESSAGE_MAP()


// CExportStudentScore 消息处理程序


void CExportStudentScore::OnBnClickedButtonOpen()
{
	UpdateData();
	CString m_cSisDes = "E:\\WellData";//GetCurrentPath();
	BROWSEINFO bi;
	char Buffer[MAX_PATH];
	//初始化入口参数bi开始
	bi.hwndOwner = NULL;
	bi.pidlRoot =NULL;//初始化制定的root目录很不容易
	bi.pszDisplayName = Buffer;//此参数如为NULL则不能显示对话框
	bi.lpszTitle = "选择测井文件目录";
	bi.ulFlags = BIF_EDITBOX;  
	CFileFind   finder;
	if(finder.FindFile(m_cSisDes)==FALSE)
	{
		bi.lParam =0;
		bi.lpfn = NULL;
	}
	else
	{
		bi.lParam = (long)(m_cSisDes.GetBuffer(m_cSisDes.GetLength()));//初始化路径，形如(_T("c:\\Symbian"));
		bi.lpfn = AddFileFolder;
	}
	finder.Close();
	bi.iImage=0;
	//初始化入口参数bi结束
	LPITEMIDLIST pIDList = SHBrowseForFolder(&bi);//调用显示选择对话框
	if(pIDList)
	{
		SHGetPathFromIDList(pIDList, Buffer);
		//取得文件夹路径到Buffer里
		m_cSisDes = Buffer;//将路径保存在一个CString对象里
	}
	m_FilePath = m_cSisDes;
	UpdateData(FALSE);

	// free memory used     
	IMalloc * imalloc = 0;
	if ( SUCCEEDED(SHGetMalloc( &imalloc)))
	{
		imalloc->Free (pIDList);
		imalloc->Release();
	}

	fpath = m_FilePath;
	fpath=fpath+"\\*.txt";
}
