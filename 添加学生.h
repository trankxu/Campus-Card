#pragma once


// ���ѧ�� �Ի���

class ���ѧ�� : public CDialogEx
{
	DECLARE_DYNAMIC(���ѧ��)

public:
	���ѧ��(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~���ѧ��();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_username;
	CString m_Pwd;
	CString m_Name;
	CString m_College;
	CString m_Class;
	CString m_Dorm;
	afx_msg void OnBnClickedOk();
};
