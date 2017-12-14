// InputPara.cpp : 实现文件
//

#include "stdafx.h"
#include "TravelMode_Classifier.h"
#include "InputPara.h"
#include "afxdialogex.h"


// InputPara 对话框

IMPLEMENT_DYNAMIC(InputPara, CDialogEx)

InputPara::InputPara(CWnd* pParent /*=NULL*/)
	: CDialogEx(InputPara::IDD, pParent)
{

	EnableAutomation();

}

InputPara::~InputPara()
{
}

void InputPara::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void InputPara::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(InputPara, CDialogEx)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(InputPara, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IInputPara 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {2EEE51E3-1A98-4606-9818-C4BCCA03EE65}
static const IID IID_IInputPara =
{ 0x2EEE51E3, 0x1A98, 0x4606, { 0x98, 0x18, 0xC4, 0xBC, 0xCA, 0x3, 0xEE, 0x65 } };

BEGIN_INTERFACE_MAP(InputPara, CDialogEx)
	INTERFACE_PART(InputPara, IID_IInputPara, Dispatch)
END_INTERFACE_MAP()


// InputPara 消息处理程序
