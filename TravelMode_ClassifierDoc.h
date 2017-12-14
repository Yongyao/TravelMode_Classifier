
// TravelMode_ClassifierDoc.h : CTravelMode_ClassifierDoc ��Ľӿ�
//


#pragma once
#include "GPoint.h"


class CTravelMode_ClassifierDoc : public CDocument
{
protected: // �������л�����
	CTravelMode_ClassifierDoc();
	DECLARE_DYNCREATE(CTravelMode_ClassifierDoc)

// ����
public:

// ����
public:
	//void split(const std::string& s, char delim, std::vector<std::string>& elems);

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CTravelMode_ClassifierDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnTravelmodeanalysisGpsdata();
	
	afx_msg void OnTravelmodeanalysisMovingwindow();
	double DirectDistance(GPoint p1, GPoint p2);
	double ToRadians(double degrees);
};
