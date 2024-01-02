// PSOView.cpp : implementation of the CPSOView class
//

#include "stdafx.h"
#include "PSO.h"

#include "PSODoc.h"
#include "PSOView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPSOView

IMPLEMENT_DYNCREATE(CPSOView, CView)

BEGIN_MESSAGE_MAP(CPSOView, CView)
	//{{AFX_MSG_MAP(CPSOView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPSOView construction/destruction

CPSOView::CPSOView()
{
	// TODO: add construction code here

}

CPSOView::~CPSOView()
{
}

BOOL CPSOView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPSOView drawing

void CPSOView::OnDraw(CDC* pDC)
{
	CPSODoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPSOView printing

BOOL CPSOView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPSOView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPSOView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPSOView diagnostics

#ifdef _DEBUG
void CPSOView::AssertValid() const
{
	CView::AssertValid();
}

void CPSOView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPSODoc* CPSOView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPSODoc)));
	return (CPSODoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPSOView message handlers
