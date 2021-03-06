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

// 初始化—连接数据库
void  ADOConn::OnInitADOConn()
{
	// 初始化OLE/COM库环境
	//AfxOleInit(); 
	::CoInitialize(NULL);

	try
	{
		// 创建Connection对象
		m_pConnection.CreateInstance("ADODB.Connection");
		//m_pConnection.CreateInstance(__uuidof(Connection));
		//_bstr_t strConnect = "Provider=SQLOLEDB.1;Password=123;Persist Security Info=True;User ID=sa;Initial Catalog=校园一卡通;Data Source=."; //关于数据库连接的各项信息  
		m_pConnection->Open("Provider = MSDASQL.1;Driver= {MySQL ODBC 8.0 Unicode Driver};DSN = cpscarddata;SERVER = localhost;DATABASE = cpscard;PORT = 3306 ","root","1Q2QQ3QQQ.", adModeUnknown);//使用Open方法连接数据库  
	}
	// 捕捉异常
	catch (_com_error e)
	{
		// 显示错误信息
		AfxMessageBox(e.Description());
	}
}

// 执行代码
_RecordsetPtr&  ADOConn::GetRecordSet(_bstr_t bstrSQL)
{
	try
	{
		// 连接数据库，如果Connection对象为空，则重新连接数据库
		if (m_pConnection == NULL)
			OnInitADOConn();
		// 创建记录集对象
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		// 取得表中的记录
		m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	// 捕捉异常
	catch (_com_error e)
	{
		// 显示错误信息
		AfxMessageBox(e.Description());
	}
	// 返回记录集
	return m_pRecordset;
}

// 执行SQL语句，Insert Update _variant_t
BOOL ADOConn::ExecuteSQL(_bstr_t bstrSQL)
{
	//    _variant_t RecordsAffected;
	try
	{
		// 是否已经连接数据库
		if (m_pConnection == NULL)
			OnInitADOConn();
		else
		{
			printf("lianjiechenggong1");
		}
		// Connection对象的Execute方法:(_bstr_t CommandText, 
		// VARIANT * RecordsAffected, long Options ) 
		// 其中CommandText是命令字串，通常是SQL命令。
		// 参数RecordsAffected是操作完成后所影响的行数, 
		// 参数Options表示CommandText的类型：adCmdText-文本命令；adCmdTable-表名
		// adCmdProc-存储过程；adCmdUnknown-未知
		m_pConnection->Execute(bstrSQL, NULL, adCmdText);
		return true;
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
		return false;
	}
}
//关闭连接
void ADOConn::ExitConnect()
{
	// 关闭记录集和连接
	if (m_pRecordset != NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
	// 释放环境
	::CoUninitialize();
}