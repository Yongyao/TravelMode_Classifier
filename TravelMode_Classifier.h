
// TravelMode_Classifier.h : TravelMode_Classifier Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CTravelMode_ClassifierApp:
// �йش����ʵ�֣������ TravelMode_Classifier.cpp
//

class CTravelMode_ClassifierApp : public CWinAppEx
{
public:
	CTravelMode_ClassifierApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTravelMode_ClassifierApp theApp;
