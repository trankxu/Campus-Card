#pragma once
#include "afxwin.h"
#include "CUsers.h"



// LoginDlg �Ի���

class LoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LoginDlg)

public:
	LoginDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LoginDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Login };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	CEdit C_UserName;
	CString m_Pwd;
	CString m_UserName;
	afx_msg void OnBnClickedOk();
};




