// DialogPara.cpp : 实现文件
//

#include "stdafx.h"
#include "TravelMode_Classifier.h"
#include "DialogPara.h"
#include "afxdialogex.h"


// CDialogPara 对话框

IMPLEMENT_DYNAMIC(CDialogPara, CDialogEx)

CDialogPara::CDialogPara(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogPara::IDD, pParent)
	, m_Vt(0)
	, m_T1(0)
	, m_T2(0)
	, m_T3(0)
	, m_Vs(0)
	, m_windowsize(0)
{

	EnableAutomation();

	m_inputfile_name = _T("");
}

CDialogPara::~CDialogPara()
{
}

void CDialogPara::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void CDialogPara::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, InputFilename);
	DDX_Text(pDX, IDC_EDIT1, m_inputfile_name);
	DDX_Text(pDX, IDC_EDIT2, m_Vt);
	DDX_Text(pDX, IDC_EDIT4, m_T1);
	DDX_Text(pDX, IDC_EDIT5, m_T2);
	DDX_Text(pDX, IDC_EDIT6, m_T3);
	DDX_Text(pDX, IDC_EDIT7, m_Vs);
	DDX_Text(pDX, IDC_EDIT3, m_windowsize);
}


BEGIN_MESSAGE_MAP(CDialogPara, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogPara::OnBnClickedButton1)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CDialogPara, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IDialogPara 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {FB713231-28E1-4739-9AFE-1C0C4F308D2D}
static const IID IID_IDialogPara =
{ 0xFB713231, 0x28E1, 0x4739, { 0x9A, 0xFE, 0x1C, 0xC, 0x4F, 0x30, 0x8D, 0x2D } };

BEGIN_INTERFACE_MAP(CDialogPara, CDialogEx)
	INTERFACE_PART(CDialogPara, IID_IDialogPara, Dispatch)
END_INTERFACE_MAP()


// CDialogPara 消息处理程序


void CDialogPara::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK)
	{
		m_inputfile_name = dlg.GetPathName();
		UpdateData(FALSE);

	}

}
