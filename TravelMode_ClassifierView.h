
// TravelMode_ClassifierView.h : CTravelMode_ClassifierView ��Ľӿ�
//

#pragma once


class CTravelMode_ClassifierView : public CView
{
protected: // �������л�����
	CTravelMode_ClassifierView();
	DECLARE_DYNCREATE(CTravelMode_ClassifierView)

// ����
public:
	CTravelMode_ClassifierDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CTravelMode_ClassifierView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // TravelMode_ClassifierView.cpp �еĵ��԰汾
inline CTravelMode_ClassifierDoc* CTravelMode_ClassifierView::GetDocument() const
   { return reinterpret_cast<CTravelMode_ClassifierDoc*>(m_pDocument); }
#endif

