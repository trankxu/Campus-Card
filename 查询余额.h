#pragma once


// ��ѯ��� �Ի���

class ��ѯ��� : public CDialogEx
{
	DECLARE_DYNAMIC(��ѯ���)

public:
	��ѯ���(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~��ѯ���();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	CString m_balance;
	afx_msg void OnPaint();
	CString m_balance2;
};
