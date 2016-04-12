
#include "stdafx.h"
#include "mainfrm.h"
#include "FileView.h"
#include "Resource.h"
#include "NewProject.h"
#include "ExportStudentScore.h"
#include "GridData.h"
#include "GraphData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif



/////////////////////////////////////////////////////////////////////////////
// CFileView

CFileView::CFileView()
{
}

CFileView::~CFileView()
{
}

BEGIN_MESSAGE_MAP(CFileView, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_PROPERTIES, OnProperties)
	ON_COMMAND(ID_OPEN, OnFileOpen)
	ON_COMMAND(ID_OPEN_WITH, OnFileOpenWith)
	ON_COMMAND(ID_DUMMY_COMPILE, OnDummyCompile)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_WM_PAINT()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkspaceBar ��Ϣ�������

int CFileView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// ������ͼ:
	const DWORD dwViewStyle = WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS;

	if (!m_wndFileView.Create(dwViewStyle, rectDummy, this, 4))
	{
		TRACE0("δ�ܴ����ļ���ͼ\n");
		return -1;      // δ�ܴ���
	}

	// ������ͼͼ��:
	m_FileViewImages.Create(IDB_FILE_VIEW, 16, 0, RGB(255, 0, 255));
	m_wndFileView.SetImageList(&m_FileViewImages, TVSIL_NORMAL);

	m_wndToolBar.Create(this, AFX_DEFAULT_TOOLBAR_STYLE, IDR_EXPLORER);
	m_wndToolBar.LoadToolBar(IDR_EXPLORER, 0, 0, TRUE /* ������*/);

	OnChangeVisualStyle();

	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);

	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() & ~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT));

	m_wndToolBar.SetOwner(this);

	// �������ͨ���˿ؼ�·�ɣ�������ͨ�������·��:
	m_wndToolBar.SetRouteCommandsViaFrame(FALSE);

	// ����һЩ��̬����ͼ����(�˴�ֻ������������룬�����Ǹ��ӵ�����)
	FillFileView();
	AdjustLayout();

	return 0;
}

void CFileView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout();
}

void CFileView::FillFileView()
{
	hRoot = m_wndFileView.InsertItem(_T("ѧ����Ϣ"), 0, 0);
	m_wndFileView.SetItemState(hRoot, TVIS_BOLD, TVIS_BOLD);

	m_wndFileView.Expand(hRoot, TVE_EXPAND);
}

void CFileView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	CTreeCtrl* pWndTree = (CTreeCtrl*) &m_wndFileView;
	ASSERT_VALID(pWndTree);

	if (pWnd != pWndTree)
	{
		CDockablePane::OnContextMenu(pWnd, point);
		return;
	}

	if (point != CPoint(-1, -1))
	{
		// ѡ���ѵ�������:
		CPoint ptTree = point;
		pWndTree->ScreenToClient(&ptTree);

		UINT flags = 0;
		HTREEITEM hTreeItem = pWndTree->HitTest(ptTree, &flags);
		if (hTreeItem != NULL)
		{
			pWndTree->SelectItem(hTreeItem);
		}
	}

	pWndTree->SetFocus();
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EXPLORER, point.x, point.y, this, TRUE);
}

void CFileView::AdjustLayout()
{
	if (GetSafeHwnd() == NULL)
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);

	int cyTlb = m_wndToolBar.CalcFixedLayout(FALSE, TRUE).cy;

	m_wndToolBar.SetWindowPos(NULL, rectClient.left, rectClient.top, rectClient.Width(), cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);
	m_wndFileView.SetWindowPos(NULL, rectClient.left + 1, rectClient.top + cyTlb + 1, rectClient.Width() - 2, rectClient.Height() - cyTlb - 2, SWP_NOACTIVATE | SWP_NOZORDER);
}

void CFileView::OnProperties()
{
	AfxMessageBox(_T("����...."));

}

void CFileView::OnFileOpen()
{
	// TODO: �ڴ˴���������������
}

void CFileView::OnFileOpenWith()
{
	// TODO: �ڴ˴���������������
}

void CFileView::OnDummyCompile()
{
	// TODO: �ڴ˴���������������
}

void CFileView::OnEditCut()
{
	// TODO: �ڴ˴���������������
}

void CFileView::OnEditCopy()
{
	// TODO: �ڴ˴���������������
}

void CFileView::OnEditClear()
{
	// TODO: �ڴ˴���������������
}

void CFileView::OnPaint()
{
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������

	CRect rectTree;
	m_wndFileView.GetWindowRect(rectTree);
	ScreenToClient(rectTree);

	rectTree.InflateRect(1, 1);
	dc.Draw3dRect(rectTree, ::GetSysColor(COLOR_3DSHADOW), ::GetSysColor(COLOR_3DSHADOW));
}

void CFileView::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);

	m_wndFileView.SetFocus();
}

void CFileView::OnChangeVisualStyle()
{
	m_wndToolBar.CleanUpLockedImages();
	m_wndToolBar.LoadBitmap(theApp.m_bHiColorIcons ? IDB_EXPLORER_24 : IDR_EXPLORER, 0, 0, TRUE /* ����*/);

	m_FileViewImages.DeleteImageList();

	UINT uiBmpId = theApp.m_bHiColorIcons ? IDB_FILE_VIEW_24 : IDB_FILE_VIEW;

	CBitmap bmp;
	if (!bmp.LoadBitmap(uiBmpId))
	{
		TRACE(_T("�޷�����λͼ: %x\n"), uiBmpId);
		ASSERT(FALSE);
		return;
	}

	BITMAP bmpObj;
	bmp.GetBitmap(&bmpObj);

	UINT nFlags = ILC_MASK;

	nFlags |= (theApp.m_bHiColorIcons) ? ILC_COLOR24 : ILC_COLOR4;

	m_FileViewImages.Create(16, bmpObj.bmHeight, nFlags, 0, 0);
	m_FileViewImages.Add(&bmp, RGB(255, 0, 255));

	m_wndFileView.SetImageList(&m_FileViewImages, TVSIL_NORMAL);
}




void CFileView::OnAddstudent()
{
	// TODO: �ڴ���������������
	CFileDialog m_dlg(TRUE,_T("*.txt||*.xls||*.xlsx"),NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT|OFN_ENABLESIZING,_T("�����ļ�(*txt;*xls;*xlsx)||"),NULL);
	m_dlg.m_ofn.lpstrTitle = _T("��ѡ�������ļ�");
	if (m_dlg.DoModal() == IDCANCEL)
	{
		return;
	}
	CString filepath = m_dlg.GetPathName();
	CString ext = m_dlg.GetFileExt();
	if (ext == _T("txt"))
	{
		OpenTextFile(filepath);
	}
	else
	{
		OpenExcelFile(filepath);
	}
}

void CFileView::OpenTextFile(CString filepath)
{
	CStdioFile TheFile(filepath,CFile::modeRead|CFile::typeBinary);
	int FileLenth = TheFile.GetLength();
	if (FileLenth == 0)
	{
		MessageBox(_T(""));
		return;
	}
	
	CString* FileData = new CString[FileLenth];
	CString strTemp;
	int step = 0;
	do
	{
		BOOL IsRead = TheFile.ReadString(strTemp);
		strTemp.Replace(_T("\t"),_T(" "));
		strTemp.Replace(_T("\n"),_T(""));
		strTemp.Replace(_T("\r"),_T(""));
		FileData[step++] = strTemp;
	}
	while(TheFile.GetPosition() < FileLenth);
	int i,j,k;
	int TotalRowNum = step;
	int TotalColNum = 0;

	CStringArray *strarry = new CStringArray[TotalRowNum];
	char *s = FileData[0].GetBuffer(FileData[0].GetLength());
	const char *d = " ";
	char *p;
	p = strtok(s,d);
	strarry[0].Add(p);
	while(p)
	{
		p=strtok(NULL,d);
		TotalColNum++;
		strarry[0].Add(p);
	}

	for (i=1;i<TotalRowNum;i++)
	{
		char *s = FileData[i].GetBuffer(FileData[i].GetLength());
		const char *d = " ";
		char *p;
		p = strtok(s,d);
		strarry[i].Add(p);
		while(p)
		{
			p=strtok(NULL,d);
			strarry[i].Add(p);
		}
	}
	int StudentNameNum = -1;
	for (i=0;i<TotalColNum;i++)
	{
		CString str = strarry[0].GetAt(i);
		if (str == _T("����"))
		{
			StudentNameNum = i;
		}
	}
	if (StudentNameNum == -1)
	{
		return;
	}
	for (i=1;i<TotalRowNum;i++)
	{
		HTREEITEM temp = m_wndFileView.InsertItem(strarry[i].GetAt(StudentNameNum),0,0,hRoot);
		m_wndFileView.Expand(temp,TVE_EXPAND);
		m_NameTree.Add(temp);
	}
	m_wndFileView.Expand(hRoot,TVE_EXPAND);

	delete []strarry;
	delete []FileData;
}

void CFileView::OpenExcelFile(CString filepath)
{
	
}

void CFileView::OnAddScore()
{
	CExportStudentScore m_dlg;
	if (m_dlg.DoModal() != IDOK)
	{
		return;
	}
	CString filePath = m_dlg.fpath;
	CString HasThisLog;
	int i=0;
	int lenth = m_NameTree.GetSize();
	for (i<0;i<lenth;i++)
	{
		HTREEITEM temp = m_NameTree.GetAt(i);
 		CString Nodename1 = m_wndFileView.GetItemText(temp);
 		CString Nodename = Nodename1 + ".txt";
		if (HasThisLog.Find(Nodename1+",",0) >= 0)
		{
			m_wndFileView.Expand(temp,TVE_EXPAND);
			continue;
		}
		CString tempname;
		CFileFind file;
		BOOL b=file.FindFile(filePath);
		if(!b) return;
		CString name;
		BOOL IsFind = FALSE;
		do 
		{
			b=file.FindNextFile();
			name = file.GetFileName();
			if(Nodename.Compare(name) == 0)
			{
				IsFind = TRUE;
				tempname = file.GetFilePath();
				break;
			}

		} while(b);
		if(IsFind == FALSE)
		{
			continue;
		}
		HasThisLog += Nodename1+",";
		CStdioFile TheFile(tempname,CFile::modeRead|CFile::typeBinary);
		int FileLenth = TheFile.GetLength();
		if (FileLenth == 0)
		{
			continue;;
		}
		CString* FileData = new CString[FileLenth];
		CString strTemp;
		int step = 0;
		do
		{
			BOOL IsRead = TheFile.ReadString(strTemp);
			strTemp.Replace(_T("\t"),_T(" "));
			strTemp.Replace(_T("\n"),_T(""));
			strTemp.Replace(_T("\r"),_T(""));
			FileData[step++] = strTemp;
		}
		while(TheFile.GetPosition() < FileLenth);
		int i,j,k;
		int TotalRowNum = step;
		int TotalColNum = 0;

		CStringArray *strarry = new CStringArray[TotalRowNum];
		char *s = FileData[0].GetBuffer(FileData[0].GetLength());
		const char *d = " ";
		char *p;
		p = strtok(s,d);
		strarry[0].Add(p);
		while(p)
		{
			p=strtok(NULL,d);
			TotalColNum++;
			strarry[0].Add(p);
		}

		for (i=1;i<TotalRowNum;i++)
		{
			char *s = FileData[i].GetBuffer(FileData[i].GetLength());
			const char *d = " ";
			char *p;
			p = strtok(s,d);
			strarry[i].Add(p);
			while(p)
			{
				p=strtok(NULL,d);
				strarry[i].Add(p);
			}
		}
		//
		CGridData* m_tempGrid = new CGridData();
		CGraphData* m_tempGraph = new CGraphData();
		//�������
		HTREEITEM ItemGrid = m_wndFileView.InsertItem(Nodename1+_T("�ɼ���"),1,1,temp);
		m_wndFileView.SetItemData(ItemGrid,(DWORD)(&m_tempGrid));
		//����ͼ��
		HTREEITEM ItemGraph = m_wndFileView.InsertItem(Nodename1+_T("�ɼ�����ͼ"),2,2,temp);
		m_wndFileView.SetItemData(ItemGraph,(DWORD)(&m_tempGraph));
		//չ�����ṹ
		m_wndFileView.Expand(ItemGrid,TVE_EXPAND);
		m_wndFileView.Expand(ItemGraph,TVE_EXPAND);
		m_wndFileView.Expand(temp,TVE_EXPAND);
	}
	m_wndFileView.Expand(hRoot,TVE_EXPAND);
}
void CFileView::OnAddWorks()
{

}
