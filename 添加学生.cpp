// ���ѧ��.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "У԰һ��ͨ����ϵͳ.h"
#include "���ѧ��.h"
#include "afxdialogex.h"
#include "CUsers.h"


// ���ѧ�� �Ի���

IMPLEMENT_DYNAMIC(���ѧ��, CDialogEx)

���ѧ��::���ѧ��(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, m_username(_T(""))
	, m_Pwd(_T(""))
	, m_Name(_T(""))
	, m_College(_T(""))
	, m_Class(_T(""))
	, m_Dorm(_T(""))
{

}

���ѧ��::~���ѧ��()
{
}

void ���ѧ��::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDX_Text(pDX, IDC_EDIT2, m_Pwd);
	DDX_Text(pDX, IDC_EDIT5, m_Name);
	DDX_Text(pDX, IDC_EDIT6, m_College);
	DDX_Text(pDX, IDC_EDIT7, m_Class);
	DDX_Text(pDX, IDC_EDIT8, m_Dorm);
}


BEGIN_MESSAGE_MAP(���ѧ��, CDialogEx)
	ON_BN_CLICKED(IDOK, &���ѧ��::OnBnClickedOk)
END_MESSAGE_MAP()


// ���ѧ�� ��Ϣ�������


void ���ѧ��::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CUsers new_user;
	new_user.SetUserName(m_username);
	new_user.SetPwd(m_Pwd);
	new_user.SetName(m_Name);
	new_user.SetCollege(m_College);
	new_user.SetClass(m_Class);
	new_user.SetDorm(m_Dorm);
	if (m_username == "null" || m_Pwd == "null" || m_Name == "null" || m_College == "null" || m_Class == "null" || m_Dorm == "null") {
		MessageBox(TEXT("��������д��"));
		return;
	}
	else
	{
		new_user.New();
	}
	MessageBox(TEXT("��ӳɹ���"));

}
