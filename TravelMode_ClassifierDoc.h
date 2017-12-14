
// TravelMode_ClassifierDoc.h : CTravelMode_ClassifierDoc 类的接口
//


#pragma once
#include "GPoint.h"


class CTravelMode_ClassifierDoc : public CDocument
{
protected: // 仅从序列化创建
	CTravelMode_ClassifierDoc();
	DECLARE_DYNCREATE(CTravelMode_ClassifierDoc)

// 特性
public:

// 操作
public:
	//void split(const std::string& s, char delim, std::vector<std::string>& elems);

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CTravelMode_ClassifierDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnTravelmodeanalysisGpsdata();
	
	afx_msg void OnTravelmodeanalysisMovingwindow();
	double DirectDistance(GPoint p1, GPoint p2);
	double ToRadians(double degrees);
};
