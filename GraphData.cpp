#include "StdAfx.h"
#include "resource.h"
#include "GraphData.h"


CGraphData::CGraphData(void)
{
}


CGraphData::~CGraphData(void)
{
}

void CGraphData::OnTreeDblClick()
{
	int lenth = gtitle.GetLength();
	TCHAR* c = gtitle.GetBuffer(lenth);
	AfxGetApp()->m_pMainWnd->SendMessage(ID_GRAPH_VIEW,(WPARAM)this,(LPARAM)c);
}

void CGraphData::OnDraw(CRect rect,CDC *pDC,CPoint Pos)
{
	//
}
