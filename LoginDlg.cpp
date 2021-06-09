// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "У԰һ��ͨ����ϵͳ.h"
#include "LoginDlg.h"
#include "afxdialogex.h"

#include "У԰һ��ͨ����ϵͳDlg.h"
#include "AdminDlg.h"



// LoginDlg �Ի���

IMPLEMENT_DYNAMIC(LoginDlg, CDialogEx)

LoginDlg::LoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Login, pParent)
	, m_Pwd(_T(""))
	, m_UserName(_T(""))
{

}

LoginDlg::~LoginDlg()
{
}

void LoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, C_UserName);
	DDX_Text(pDX, IDC_EDIT2, m_Pwd);
	DDX_Text(pDX, IDC_EDIT1, m_UserName);
}


BEGIN_MESSAGE_MAP(LoginDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &LoginDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// LoginDlg ��Ϣ�������


void LoginDlg::OnBnClickedOk()
{
	//���Ի����б༭������ݶ�ȡ����Ա������
	UpdateData(TRUE);
	//���������Ч��
	if (m_UserName == "")
	{
		MessageBox(TEXT("�������û���,�������"));
		return;



	}
	if (m_Pwd == "")
	{
		MessageBox(TEXT("����������"));
		return;
	}
	//����CUsers�������ڴӱ�Users�ж�ȡ����
	CUsers user;
	if (user.Login(m_UserName)) {
		
		//�����ȡ���������û��������ݲ�ͬ���򷵻�
		if (user.GetPwd() != m_Pwd)
		{
			CString s,b,t;
			t = m_UserName;
			s = user.GetPwd();
			b = m_Pwd;
			MessageBox(s);
			MessageBox(b);
			MessageBox(t);
			MessageBox(TEXT("�û���Ϣ����"));
			return;
		}
		
		
			
	}
	else
	{
		MessageBox(TEXT("�û��������ڣ�"));
	}
	//�رնԻ���		

	CDialogEx::OnOK();
	CString s("safe");
	CString a("A");
	
	if (user.GetUser_type() ==  s) {
		CУ԰һ��ͨ����ϵͳDlg mydlg;
		mydlg.m_UserName = m_UserName;
		mydlg.DoModal();
	}
	else
		if (user.GetUser_type() == a) {
			AdminDlg mydlg;
			mydlg.DoModal();
		}
		else
			MessageBox(TEXT("�Ƿ����û����ͣ�"));
}


