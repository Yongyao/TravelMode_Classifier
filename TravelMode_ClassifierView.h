
// TravelMode_ClassifierView.h : CTravelMode_ClassifierView 类的接口
//

#pragma once


class CTravelMode_ClassifierView : public CView
{
protected: // 仅从序列化创建
	CTravelMode_ClassifierView();
	DECLARE_DYNCREATE(CTravelMode_ClassifierView)

// 特性
public:
	CTravelMode_ClassifierDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CTravelMode_ClassifierView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // TravelMode_ClassifierView.cpp 中的调试版本
inline CTravelMode_ClassifierDoc* CTravelMode_ClassifierView::GetDocument() const
   { return reinterpret_cast<CTravelMode_ClassifierDoc*>(m_pDocument); }
#endif

