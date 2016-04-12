#pragma once
#include "basedata.h"
#include "GridCtrl.h"
class CGridData : public CBaseData
{
public:
	CGridData(void);
	~CGridData(void);
public:
	CGridCtrl m_Gird;
	void CreateGrid();
	virtual void OnTreeDblClick();
};

