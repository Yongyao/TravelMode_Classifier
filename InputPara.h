#pragma once


// InputPara �Ի���

class InputPara : public CDialogEx
{
	DECLARE_DYNAMIC(InputPara)

public:
	InputPara(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~InputPara();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_DIALOG_PARA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};
