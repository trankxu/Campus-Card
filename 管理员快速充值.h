#pragma once


// ����Ա���ٳ�ֵ �Ի���

class ����Ա���ٳ�ֵ : public CDialogEx
{
	DECLARE_DYNAMIC(����Ա���ٳ�ֵ)

public:
	����Ա���ٳ�ֵ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~����Ա���ٳ�ֵ();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_username;
	int m_ChongZhi;
	afx_msg void OnBnClickedOk();
};
