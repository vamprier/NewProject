#pragma once
#include "basedata.h"
class CGraphData : public CBaseData
{
public:
	CGraphData(void);
	~CGraphData(void);
public:
	CString gtitle;    //ͼ��
public:
	virtual void OnTreeDblClick();
	virtual void OnDraw(CRect rect,CDC *pDC,CPoint Pos);
};

