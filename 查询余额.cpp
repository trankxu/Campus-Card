// ��ѯ���.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "У԰һ��ͨ����ϵͳ.h"
#include "��ѯ���.h"
#include "afxdialogex.h"
#include "CUsers.h"



// ��ѯ��� �Ի���

IMPLEMENT_DYNAMIC(��ѯ���, CDialogEx)

��ѯ���::��ѯ���(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_balance(_T(""))
	, m_balance2(_T(""))
{

	//  m_username = _T("");
}

��ѯ���::~��ѯ���()
{
}

void ��ѯ���::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_balance);
	DDX_Text(pDX, IDC_EDIT2, m_balance2);
}


BEGIN_MESSAGE_MAP(��ѯ���, CDialogEx)
	ON_BN_CLICKED(IDOK, &��ѯ���::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &��ѯ���::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &��ѯ���::OnEnChangeEdit1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// ��ѯ��� ��Ϣ�������


void ��ѯ���::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CDialogEx::OnOK();
}


void ��ѯ���::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void ��ѯ���::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void ��ѯ���::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CUsers user1;
	user1.SearchName(m_balance);
	GetDlgItem(IDC_EDIT1)->SetWindowText((LPCTSTR)user1.GetName());

	user1.SearchBalance(m_balance);
	CString p;
	p.Format(_T("%.2f"), user1.GetBalance());
	GetDlgItem(IDC_EDIT2)->SetWindowText((LPCTSTR)p);

	//GetDlgItem(IDC_EDIT1)->SetWindowText((LPCTSTR)USERNAME);
	// TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}
