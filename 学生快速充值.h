#pragma once
#include "afxwin.h"


// ѧ�����ٳ�ֵ �Ի���

class ѧ�����ٳ�ֵ : public CDialogEx
{
	DECLARE_DYNAMIC(ѧ�����ٳ�ֵ)

public:
	ѧ�����ٳ�ֵ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ѧ�����ٳ�ֵ();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CZ_xiaoyuanwang };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_ChongZhi;
	CString m_Pwd;
	double m_Balance;
	CComboBox m_ComboBox;
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnPaint();
	CString m_username;
};
