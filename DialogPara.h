#pragma once
#include "afxwin.h"


// CDialogPara �Ի���

class CDialogPara : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogPara)

public:
	CDialogPara(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogPara();

	virtual void OnFinalRelease();

// �Ի�������
	enum { IDD = IDD_DIALOG_Para };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
//	CEdit InputFilename;
	afx_msg void OnBnClickedButton1();
	CString m_inputfile_name;
	float m_Vt;
	float m_T1;
	float m_T2;
	float m_T3;
	float m_Vs;
	int m_windowsize;
};
