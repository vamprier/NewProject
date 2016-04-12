#pragma once
class CBaseData
{
public:
	CBaseData(void);
	~CBaseData(void);
public:
	virtual void OnTreeDblClick();
	virtual void OnDraw(CRect rect,CDC *pDC,CPoint Pos);
};

