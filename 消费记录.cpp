// ���Ѽ�¼.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "У԰һ��ͨ����ϵͳ.h"
#include "���Ѽ�¼.h"
#include "afxdialogex.h"


// ���Ѽ�¼ �Ի���

IMPLEMENT_DYNAMIC(���Ѽ�¼, CDialogEx)

���Ѽ�¼::���Ѽ�¼(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PurchaseHistory, pParent)
	, m_UserName(_T(""))
{

}

���Ѽ�¼::~���Ѽ�¼()
{
}

void ���Ѽ�¼::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_���Ѽ�¼List);
	DDX_Text(pDX, IDC_EDIT1, m_UserName);
}


BEGIN_MESSAGE_MAP(���Ѽ�¼, CDialogEx)

	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST3, &���Ѽ�¼::OnLvnItemchangedList3)
END_MESSAGE_MAP()


// ���Ѽ�¼ ��Ϣ�������


BOOL ���Ѽ�¼::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect rect;
	m_���Ѽ�¼List.GetClientRect(&rect);
	m_���Ѽ�¼List.SetExtendedStyle(m_���Ѽ�¼List.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_���Ѽ�¼List.InsertColumn(0, _T("ʱ��"), LVCFMT_CENTER, rect.Width() / 3*2, 0);
	m_���Ѽ�¼List.InsertColumn(1, _T("���ѽ��"), LVCFMT_CENTER, rect.Width() / 3, 1);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}





void ���Ѽ�¼::OnLvnItemchangedList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	
}
