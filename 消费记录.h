#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// ���Ѽ�¼ �Ի���

class ���Ѽ�¼ : public CDialogEx
{
	DECLARE_DYNAMIC(���Ѽ�¼)

public:
	���Ѽ�¼(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~���Ѽ�¼();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PurchaseHistory };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	afx_msg void OnLvnItemchangedList3(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_���Ѽ�¼List;
	CString m_UserName;
};
