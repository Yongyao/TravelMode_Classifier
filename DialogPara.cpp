// DialogPara.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TravelMode_Classifier.h"
#include "DialogPara.h"
#include "afxdialogex.h"


// CDialogPara �Ի���

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
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

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

// ע��: ������� IID_IDialogPara ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {FB713231-28E1-4739-9AFE-1C0C4F308D2D}
static const IID IID_IDialogPara =
{ 0xFB713231, 0x28E1, 0x4739, { 0x9A, 0xFE, 0x1C, 0xC, 0x4F, 0x30, 0x8D, 0x2D } };

BEGIN_INTERFACE_MAP(CDialogPara, CDialogEx)
	INTERFACE_PART(CDialogPara, IID_IDialogPara, Dispatch)
END_INTERFACE_MAP()


// CDialogPara ��Ϣ�������


void CDialogPara::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK)
	{
		m_inputfile_name = dlg.GetPathName();
		UpdateData(FALSE);

	}

}
