#pragma once


// ����޸� �Ի���

class ����޸� : public CDialogEx
{
	DECLARE_DYNAMIC(����޸�)

public:
	����޸�(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~����޸�();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CZ_yuexiugai };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_username;
	double m_yu_e;
	afx_msg void OnBnClickedOk();
};
