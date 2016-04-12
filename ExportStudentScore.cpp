// ExportStudentScore.cpp : ʵ���ļ�
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

// CExportStudentScore �Ի���

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


// CExportStudentScore ��Ϣ�������


void CExportStudentScore::OnBnClickedButtonOpen()
{
	UpdateData();
	CString m_cSisDes = "E:\\WellData";//GetCurrentPath();
	BROWSEINFO bi;
	char Buffer[MAX_PATH];
	//��ʼ����ڲ���bi��ʼ
	bi.hwndOwner = NULL;
	bi.pidlRoot =NULL;//��ʼ���ƶ���rootĿ¼�ܲ�����
	bi.pszDisplayName = Buffer;//�˲�����ΪNULL������ʾ�Ի���
	bi.lpszTitle = "ѡ��⾮�ļ�Ŀ¼";
	bi.ulFlags = BIF_EDITBOX;  
	CFileFind   finder;
	if(finder.FindFile(m_cSisDes)==FALSE)
	{
		bi.lParam =0;
		bi.lpfn = NULL;
	}
	else
	{
		bi.lParam = (long)(m_cSisDes.GetBuffer(m_cSisDes.GetLength()));//��ʼ��·��������(_T("c:\\Symbian"));
		bi.lpfn = AddFileFolder;
	}
	finder.Close();
	bi.iImage=0;
	//��ʼ����ڲ���bi����
	LPITEMIDLIST pIDList = SHBrowseForFolder(&bi);//������ʾѡ��Ի���
	if(pIDList)
	{
		SHGetPathFromIDList(pIDList, Buffer);
		//ȡ���ļ���·����Buffer��
		m_cSisDes = Buffer;//��·��������һ��CString������
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
