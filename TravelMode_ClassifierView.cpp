
// TravelMode_ClassifierView.cpp : CTravelMode_ClassifierView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTravelMode_ClassifierView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTravelMode_ClassifierView 构造/析构

CTravelMode_ClassifierView::CTravelMode_ClassifierView()
{
	// TODO: 在此处添加构造代码

}

CTravelMode_ClassifierView::~CTravelMode_ClassifierView()
{
}

BOOL CTravelMode_ClassifierView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTravelMode_ClassifierView 绘制

void CTravelMode_ClassifierView::OnDraw(CDC* /*pDC*/)
{
	CTravelMode_ClassifierDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CTravelMode_ClassifierView 打印


void CTravelMode_ClassifierView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTravelMode_ClassifierView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTravelMode_ClassifierView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTravelMode_ClassifierView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CTravelMode_ClassifierView 诊断

#ifdef _DEBUG
void CTravelMode_ClassifierView::AssertValid() const
{
	CView::AssertValid();
}

void CTravelMode_ClassifierView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTravelMode_ClassifierDoc* CTravelMode_ClassifierView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTravelMode_ClassifierDoc)));
	return (CTravelMode_ClassifierDoc*)m_pDocument;
}
#endif //_DEBUG


// CTravelMode_ClassifierView 消息处理程序
