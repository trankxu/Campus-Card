// AdminDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "У԰һ��ͨ����ϵͳ.h"
#include "AdminDlg.h"
#include "afxdialogex.h"

#include "����Ա���ٳ�ֵ.h"
#include "����޸�.h"
#include "���ѧ��.h"


// AdminDlg �Ի���

IMPLEMENT_DYNAMIC(AdminDlg, CDialogEx)

AdminDlg::AdminDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADMIN, pParent)
{

}

AdminDlg::~AdminDlg()
{
}

void AdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AdminDlg, CDialogEx)
	ON_COMMAND(ID_32782, &AdminDlg::On32782)
	ON_COMMAND(ID_32783, &AdminDlg::On32783)
	ON_COMMAND(ID_32784, &AdminDlg::On32784)
	ON_COMMAND(IDC_STATIC, &AdminDlg::OnStatic)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// AdminDlg ��Ϣ�������


void AdminDlg::On32782()
{
	// TODO: �ڴ���������������
	����Ա���ٳ�ֵ dlg7;
	dlg7.DoModal();

}


void AdminDlg::On32783()
{
	// TODO: �ڴ���������������
	����޸� dlg8;
	dlg8.DoModal();
}


void AdminDlg::On32784()
{
	// TODO: �ڴ���������������
	���ѧ�� dlg9;
	dlg9.DoModal();
}


void AdminDlg::OnStatic()
{
	// TODO: �ڴ���������������

}


HBRUSH AdminDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (pWnd->GetDlgCtrlID() == IDC_STATIC) {//IDC_STATIC_TEST�ǿؼ���ID
		pDC->SetTextColor(RGB(128, 128, 256));//��RGB��ı���ɫ       
	}

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}
