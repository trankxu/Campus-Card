// ����Ա���ٳ�ֵ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "У԰һ��ͨ����ϵͳ.h"
#include "����Ա���ٳ�ֵ.h"
#include "afxdialogex.h"

#include "CUsers.h"




// ����Ա���ٳ�ֵ �Ի���

IMPLEMENT_DYNAMIC(����Ա���ٳ�ֵ, CDialogEx)

����Ա���ٳ�ֵ::����Ա���ٳ�ֵ(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_username(_T(""))
	, m_ChongZhi(0)
{

}

����Ա���ٳ�ֵ::~����Ա���ٳ�ֵ()
{
}

void ����Ա���ٳ�ֵ::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDX_Text(pDX, IDC_EDIT2, m_ChongZhi);
}


BEGIN_MESSAGE_MAP(����Ա���ٳ�ֵ, CDialogEx)
	ON_BN_CLICKED(IDOK, &����Ա���ٳ�ֵ::OnBnClickedOk)
END_MESSAGE_MAP()


// ����Ա���ٳ�ֵ ��Ϣ�������


void ����Ա���ٳ�ֵ::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CUsers user;
	user.SearchBalance(m_username);
	user.SetBalance(user.GetBalance() + m_ChongZhi);
	user.UpDateBalance(m_username);
	MessageBox(TEXT("��ֵ�ɹ���"));
	CDialogEx::OnOK();
}
