// �ܲٲ�ѯ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "У԰һ��ͨ����ϵͳ.h"
#include "�ܲٲ�ѯ.h"
#include "afxdialogex.h"
#include "CUsers.h"


// �ܲٲ�ѯ �Ի���
IMPLEMENT_DYNAMIC(�ܲٲ�ѯ, CDialogEx)

�ܲٲ�ѯ::�ܲٲ�ѯ(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PAOCAO, pParent)
	, m_Name(_T(""))
	, m_RunNum(_T(""))
{

}

�ܲٲ�ѯ::~�ܲٲ�ѯ()
{
}

void �ܲٲ�ѯ::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_Text(pDX, IDC_EDIT2, m_RunNum);
}


BEGIN_MESSAGE_MAP(�ܲٲ�ѯ, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// �ܲٲ�ѯ ��Ϣ�������


void �ܲٲ�ѯ::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CUsers user1;
	user1.SearchName(m_Name);
	GetDlgItem(IDC_EDIT1)->SetWindowText((LPCTSTR)user1.GetName());

	user1.SearchMorningRunNum(m_Name);
	CString p;
	p.Format(_T("%d"), user1.GetMorningRunNum());
	GetDlgItem(IDC_EDIT2)->SetWindowText((LPCTSTR)p);

}
