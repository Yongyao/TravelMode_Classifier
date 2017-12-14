#pragma once


// InputPara 对话框

class InputPara : public CDialogEx
{
	DECLARE_DYNAMIC(InputPara)

public:
	InputPara(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~InputPara();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_DIALOG_PARA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};
