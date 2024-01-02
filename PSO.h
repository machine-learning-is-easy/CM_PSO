// PSO.h : main header file for the PSO application
//

#if !defined(AFX_PSO_H__45A7BC5F_805F_4C9C_90BA_AA9CA339A52A__INCLUDED_)
#define AFX_PSO_H__45A7BC5F_805F_4C9C_90BA_AA9CA339A52A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPSOApp:
// See PSO.cpp for the implementation of this class
//

class CPSOApp : public CWinApp
{
public:
	CPSOApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPSOApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPSOApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PSO_H__45A7BC5F_805F_4C9C_90BA_AA9CA339A52A__INCLUDED_)
