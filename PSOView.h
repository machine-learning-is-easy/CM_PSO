// PSOView.h : interface of the CPSOView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSOVIEW_H__F1F2C193_3177_46D7_83E9_A9578F3176FB__INCLUDED_)
#define AFX_PSOVIEW_H__F1F2C193_3177_46D7_83E9_A9578F3176FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPSOView : public CView
{
protected: // create from serialization only
	CPSOView();
	DECLARE_DYNCREATE(CPSOView)

// Attributes
public:
	CPSODoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPSOView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPSOView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPSOView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PSOView.cpp
inline CPSODoc* CPSOView::GetDocument()
   { return (CPSODoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PSOVIEW_H__F1F2C193_3177_46D7_83E9_A9578F3176FB__INCLUDED_)
