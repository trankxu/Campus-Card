
// У԰һ��ͨ����ϵͳ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������



// CУ԰һ��ͨ����ϵͳApp: 
// �йش����ʵ�֣������ У԰һ��ͨ����ϵͳ.cpp
//

class CУ԰һ��ͨ����ϵͳApp : public CWinApp
{
public:
	CУ԰һ��ͨ����ϵͳApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	afx_msg void On32771();
	afx_msg void On32772();
};

extern CУ԰һ��ͨ����ϵͳApp theApp;
