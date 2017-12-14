
// TravelMode_ClassifierView.cpp : CTravelMode_ClassifierView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "TravelMode_Classifier.h"
#endif

#include "TravelMode_ClassifierDoc.h"
#include "TravelMode_ClassifierView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTravelMode_ClassifierView

IMPLEMENT_DYNCREATE(CTravelMode_ClassifierView, CView)

BEGIN_MESSAGE_MAP(CTravelMode_ClassifierView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTravelMode_ClassifierView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTravelMode_ClassifierView ����/����

CTravelMode_ClassifierView::CTravelMode_ClassifierView()
{
	// TODO: �ڴ˴���ӹ������

}

CTravelMode_ClassifierView::~CTravelMode_ClassifierView()
{
}

BOOL CTravelMode_ClassifierView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CTravelMode_ClassifierView ����

void CTravelMode_ClassifierView::OnDraw(CDC* /*pDC*/)
{
	CTravelMode_ClassifierDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CTravelMode_ClassifierView ��ӡ


void CTravelMode_ClassifierView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTravelMode_ClassifierView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CTravelMode_ClassifierView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CTravelMode_ClassifierView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CTravelMode_ClassifierView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTravelMode_ClassifierView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTravelMode_ClassifierView ���

#ifdef _DEBUG
void CTravelMode_ClassifierView::AssertValid() const
{
	CView::AssertValid();
}

void CTravelMode_ClassifierView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTravelMode_ClassifierDoc* CTravelMode_ClassifierView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTravelMode_ClassifierDoc)));
	return (CTravelMode_ClassifierDoc*)m_pDocument;
}
#endif //_DEBUG


// CTravelMode_ClassifierView ��Ϣ�������
