// InputPara.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TravelMode_Classifier.h"
#include "InputPara.h"
#include "afxdialogex.h"


// InputPara �Ի���

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
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

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

// ע��: ������� IID_IInputPara ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {2EEE51E3-1A98-4606-9818-C4BCCA03EE65}
static const IID IID_IInputPara =
{ 0x2EEE51E3, 0x1A98, 0x4606, { 0x98, 0x18, 0xC4, 0xBC, 0xCA, 0x3, 0xEE, 0x65 } };

BEGIN_INTERFACE_MAP(InputPara, CDialogEx)
	INTERFACE_PART(InputPara, IID_IInputPara, Dispatch)
END_INTERFACE_MAP()


// InputPara ��Ϣ�������
