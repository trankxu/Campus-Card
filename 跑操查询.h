#pragma once


// �ܲٲ�ѯ �Ի���

class �ܲٲ�ѯ : public CDialogEx
{
	DECLARE_DYNAMIC(�ܲٲ�ѯ)

public:
	�ܲٲ�ѯ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~�ܲٲ�ѯ();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAOCAO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_Name;
	CString m_RunNum;
	afx_msg void OnPaint();
};
