
// У԰һ��ͨ����ϵͳDlg.h : ͷ�ļ�
//

#pragma once


// CУ԰һ��ͨ����ϵͳDlg �Ի���
class CУ԰һ��ͨ����ϵͳDlg : public CDialogEx
{
// ����
public:
	CУ԰һ��ͨ����ϵͳDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMfcmenubutton1();
	afx_msg void OnBnClickedButton1();

	CString m_UserName;
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32777();
	afx_msg void On32778();
};
