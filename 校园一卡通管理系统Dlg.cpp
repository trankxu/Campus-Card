
// У԰һ��ͨ����ϵͳDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "У԰һ��ͨ����ϵͳ.h"
#include "У԰һ��ͨ����ϵͳDlg.h"
#include "afxdialogex.h"

#include "��ѯ���.h"

#include "�ܲٲ�ѯ.h"
#include "���Ѽ�¼.h"
#include "ѧ�����ٳ�ֵ.h"
#include "CUsers.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CУ԰һ��ͨ����ϵͳDlg �Ի���



CУ԰һ��ͨ����ϵͳDlg::CУ԰һ��ͨ����ϵͳDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, m_UserName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CУ԰һ��ͨ����ϵͳDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_UserName);
}

BEGIN_MESSAGE_MAP(CУ԰һ��ͨ����ϵͳDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32771, &CУ԰һ��ͨ����ϵͳDlg::On32771)
	ON_COMMAND(ID_32772, &CУ԰һ��ͨ����ϵͳDlg::On32772)
	ON_COMMAND(ID_32773, &CУ԰һ��ͨ����ϵͳDlg::On32773)
	ON_COMMAND(ID_32774, &CУ԰һ��ͨ����ϵͳDlg::On32774)
	ON_COMMAND(ID_32777, &CУ԰һ��ͨ����ϵͳDlg::On32777)
	ON_COMMAND(ID_32778, &CУ԰һ��ͨ����ϵͳDlg::On32778)
END_MESSAGE_MAP()


// CУ԰һ��ͨ����ϵͳDlg ��Ϣ�������

BOOL CУ԰һ��ͨ����ϵͳDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CУ԰һ��ͨ����ϵͳDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CУ԰һ��ͨ����ϵͳDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CУ԰һ��ͨ����ϵͳDlg::On32771()
{
	��ѯ��� dlg3;
	dlg3.m_balance = m_UserName;
	dlg3.DoModal();
	// TODO: �ڴ���������������
}


void CУ԰һ��ͨ����ϵͳDlg::On32772()
{
	�ܲٲ�ѯ dlg4;
	dlg4.m_Name = m_UserName;
	dlg4.DoModal();
	// TODO: �ڴ���������������
}


void CУ԰һ��ͨ����ϵͳDlg::On32773()
{
	���Ѽ�¼ dlg5;
	dlg5.m_UserName = m_UserName;
	dlg5.DoModal();
	// TODO: �ڴ���������������
}


void CУ԰һ��ͨ����ϵͳDlg::On32774()
{
	ѧ�����ٳ�ֵ dlg6;
	dlg6.m_username = m_UserName;
	dlg6.DoModal();
	// TODO: �ڴ���������������
}


void CУ԰һ��ͨ����ϵͳDlg::On32777()
{
	CUsers user;
	user.SearchCardStatus(m_UserName);
	if(user.GetCardStatus() == "����"){
		user.SetCardStatus(_T("������"));
		user.UpDateCardStatus(m_UserName);
		MessageBox(TEXT("��ʧ�ɹ���"));
	}
	else
	{
		if (user.GetCardStatus() == "������")
			MessageBox(TEXT("�˿��Ѿ���ʧ��"));
	}
	// TODO: �ڴ���������������
}


void CУ԰һ��ͨ����ϵͳDlg::On32778()
{
	// TODO: �ڴ���������������
	CUsers user;
	user.SearchCardStatus(m_UserName);
	if (user.GetCardStatus() == "������") {
		user.SetCardStatus(_T("����"));
		user.UpDateCardStatus(m_UserName);
		MessageBox(TEXT("��ҳɹ���"));
	}
	else
	{
		if (user.GetCardStatus() == "����")
			MessageBox(TEXT("�˿���δ��ʧ��"));
	}
}
