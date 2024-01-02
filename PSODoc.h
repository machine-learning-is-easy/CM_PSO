// PSODoc.h : interface of the CPSODoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PSODOC_H__A6636829_6710_4F0F_B1EF_559DC65B5C10__INCLUDED_)
#define AFX_PSODOC_H__A6636829_6710_4F0F_B1EF_559DC65B5C10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPSODoc : public CDocument
{
protected: // create from serialization only
	CPSODoc();
	DECLARE_DYNCREATE(CPSODoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPSODoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPSODoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPSODoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PSODOC_H__A6636829_6710_4F0F_B1EF_559DC65B5C10__INCLUDED_)
