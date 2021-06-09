// ADOConn.cpp: implementation of the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ADOConn.h"
#include<iostream>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ADOConn::ADOConn()
{

}

ADOConn::~ADOConn()
{

}

// ��ʼ�����������ݿ�
void  ADOConn::OnInitADOConn()
{
	// ��ʼ��OLE/COM�⻷��
	//AfxOleInit(); 
	::CoInitialize(NULL);

	try
	{
		// ����Connection����
		m_pConnection.CreateInstance("ADODB.Connection");
		//m_pConnection.CreateInstance(__uuidof(Connection));
		//_bstr_t strConnect = "Provider=SQLOLEDB.1;Password=123;Persist Security Info=True;User ID=sa;Initial Catalog=У԰һ��ͨ;Data Source=."; //�������ݿ����ӵĸ�����Ϣ  
		m_pConnection->Open("Provider = MSDASQL.1;Driver= {MySQL ODBC 8.0 Unicode Driver};DSN = cpscarddata;SERVER = localhost;DATABASE = cpscard;PORT = 3306 ","root","1Q2QQ3QQQ.", adModeUnknown);//ʹ��Open�����������ݿ�  
	}
	// ��׽�쳣
	catch (_com_error e)
	{
		// ��ʾ������Ϣ
		AfxMessageBox(e.Description());
	}
}

// ִ�д���
_RecordsetPtr&  ADOConn::GetRecordSet(_bstr_t bstrSQL)
{
	try
	{
		// �������ݿ⣬���Connection����Ϊ�գ��������������ݿ�
		if (m_pConnection == NULL)
			OnInitADOConn();
		// ������¼������
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		// ȡ�ñ��еļ�¼
		m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	// ��׽�쳣
	catch (_com_error e)
	{
		// ��ʾ������Ϣ
		AfxMessageBox(e.Description());
	}
	// ���ؼ�¼��
	return m_pRecordset;
}

// ִ��SQL��䣬Insert Update _variant_t
BOOL ADOConn::ExecuteSQL(_bstr_t bstrSQL)
{
	//    _variant_t RecordsAffected;
	try
	{
		// �Ƿ��Ѿ��������ݿ�
		if (m_pConnection == NULL)
			OnInitADOConn();
		else
		{
			printf("lianjiechenggong1");
		}
		// Connection�����Execute����:(_bstr_t CommandText, 
		// VARIANT * RecordsAffected, long Options ) 
		// ����CommandText�������ִ���ͨ����SQL���
		// ����RecordsAffected�ǲ�����ɺ���Ӱ�������, 
		// ����Options��ʾCommandText�����ͣ�adCmdText-�ı����adCmdTable-����
		// adCmdProc-�洢���̣�adCmdUnknown-δ֪
		m_pConnection->Execute(bstrSQL, NULL, adCmdText);
		return true;
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
		return false;
	}
}
//�ر�����
void ADOConn::ExitConnect()
{
	// �رռ�¼��������
	if (m_pRecordset != NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
	// �ͷŻ���
	::CoUninitialize();
}