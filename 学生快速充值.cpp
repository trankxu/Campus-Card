// ѧ�����ٳ�ֵ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "У԰һ��ͨ����ϵͳ.h"
#include "ѧ�����ٳ�ֵ.h"
#include "afxdialogex.h"
#include "CUsers.h"


// ѧ�����ٳ�ֵ �Ի���

IMPLEMENT_DYNAMIC(ѧ�����ٳ�ֵ, CDialogEx)

ѧ�����ٳ�ֵ::ѧ�����ٳ�ֵ(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CZ_xiaoyuanwang, pParent)
	, m_ChongZhi(0)
	, m_Pwd(_T(""))
	, m_Balance(0)
	, m_username(_T(""))
{

}

ѧ�����ٳ�ֵ::~ѧ�����ٳ�ֵ()
{
}

void ѧ�����ٳ�ֵ::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_ChongZhi);
	DDX_Text(pDX, IDC_EDIT2, m_Pwd);
	DDX_Text(pDX, IDC_EDIT3, m_Balance);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBox);
	DDX_Text(pDX, IDC_EDIT4, m_username);
}


BEGIN_MESSAGE_MAP(ѧ�����ٳ�ֵ, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &ѧ�����ٳ�ֵ::OnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &ѧ�����ٳ�ֵ::OnBnClickedOk)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// ѧ�����ٳ�ֵ ��Ϣ�������


CString strtype;
int nSel;

void ѧ�����ٳ�ֵ::OnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: Add your control notification handler code here   
	


	// ��ȡ��Ͽ�ؼ����б����ѡ���������   
	nSel = m_ComboBox.GetCurSel();
	// ����ѡ����������ȡ�����ַ���   
	m_ComboBox.GetLBText(nSel, strtype);
}




void ѧ�����ٳ�ֵ::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CUsers user2;
	user2.Login(m_username);
	user2.SearchBalance(m_username);
	
	UpdateData(TRUE);
	if (user2.GetPwd() != m_Pwd) {
		MessageBox(TEXT("�������"));
	}
	else {
		user2.SearchCardStatus(m_username);
		if (user2.GetCardStatus() == "������")
		{
			MessageBox(TEXT("�˿��Ѿ���ʧ��"));
		}
		else {
			if (m_ChongZhi >= m_Balance) {
				MessageBox(TEXT("���㣡"));
				return;
			}

			if (m_ChongZhi <= 0) {
				MessageBox(TEXT("������������"));
				return;
			}
			else
			{
				if (strtype == "")
					MessageBox(TEXT("��ѡ���ֵ����"));
				else
				{
					if (strtype == "У԰��") {
						user2.SearchSchoolNetBalance(m_username);
						user2.SetSchoolNetBalance(user2.GetSchoolNetBalance() + m_ChongZhi);
						user2.SetBalance(user2.GetBalance() - m_ChongZhi);
						user2.UpDateSchoolNetBalance(m_username);
						user2.UpDateBalance(m_username);
					}
					else
					{
						if (strtype == "������") {
							user2.SearchEnergeCharge(m_username);
							user2.SetEnergeCharge(user2.GetEnergeCharge() + m_ChongZhi);
							user2.SetBalance(user2.GetBalance() - m_ChongZhi);
							user2.UpDateEnergeCharge(m_username);
							user2.UpDateBalance(m_username);
						}
						else
						{
							if (strtype == "����յ�") {
								user2.SearchAirCharge(m_username);
								user2.SetAirCharge(user2.GetAirCharge() + m_ChongZhi);
								user2.SetBalance(user2.GetBalance() - m_ChongZhi);
								user2.UpDateAirCharge(m_username);
								user2.UpDateBalance(m_username);
							}
						}
					}




					CString p;
					p.Format(_T("%.2f"), user2.GetBalance());
					GetDlgItem(IDC_EDIT3)->SetWindowText((LPCTSTR)p);
					MessageBox(TEXT("��ֵ�ɹ�"));
				}
			}
		}
	}
		

	
}


void ѧ�����ٳ�ֵ::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CUsers user2;
	user2.SetUserName(m_username);
	user2.SearchBalance(user2.GetUser_Name());
	CString p;
	p.Format(_T("%.2f"), user2.GetBalance());
	GetDlgItem(IDC_EDIT3)->SetWindowText((LPCTSTR)p);
}
