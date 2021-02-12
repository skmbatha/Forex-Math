/***************************************************************
 * Name:      ForexMathApp.cpp
 * Purpose:   Code for Application Class
 * Author:    SK MBATHA (skatlego.mbatha@gmail.com)
 * Created:   2020-12-15
 * Copyright: SK MBATHA ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "ForexMathApp.h"
#include "ForexMathMain.h"

IMPLEMENT_APP(ForexMathApp);

bool ForexMathApp::OnInit()
{
    ForexMathFrame* frame = new ForexMathFrame(0L);
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    
    return true;
}
