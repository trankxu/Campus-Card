// ����޸�.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "У԰һ��ͨ����ϵͳ.h"
#include "����޸�.h"
#include "afxdialogex.h"
#include "CUsers.h"


// ����޸� �Ի���

IMPLEMENT_DYNAMIC(����޸�, CDialogEx)

����޸�::����޸�(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CZ_yuexiugai, pParent)
	, m_username(_T(""))
	, m_yu_e(0)
{

}

����޸�::~����޸�()
{
}

void ����޸�::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDX_Text(pDX, IDC_EDIT2, m_yu_e);
}


BEGIN_MESSAGE_MAP(����޸�, CDialogEx)
	ON_BN_CLICKED(IDOK, &����޸�::OnBnClickedOk)
END_MESSAGE_MAP()


// ����޸� ��Ϣ�������


void ����޸�::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CUsers user;
	user.SearchBalance(m_username);
	user.SetBalance(m_yu_e);
	user.UpDateBalance(m_username);
	MessageBox(TEXT("�޸ĳɹ���"));
	CDialogEx::OnOK();
}
