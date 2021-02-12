/***************************************************************
 * Name:      ForexMathMain.cpp
 * Purpose:   Code for Application Frame
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

#include "ForexMathMain.h"
#include <string.h>
#include <math.h>

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

BEGIN_EVENT_TABLE(ForexMathFrame,GUIFrame)

EVT_MENU(wxID_ABOUT, ForexMathFrame::OnAbout)
EVT_MENU(wxID_EXIT, ForexMathFrame::OnQuit)
EVT_MENU(wxID_HELP, ForexMathFrame::OnHelp)
EVT_BUTTON(wxID_Calculate,ForexMathFrame::OnCalculate)
EVT_BUTTON(wxID_Clear,ForexMathFrame::OnClear)
EVT_TOGGLEBUTTON(wxID_ToggleCurrency,ForexMathFrame::OnToggleCurrency)

END_EVENT_TABLE()


ForexMathFrame::ForexMathFrame(wxFrame *frame)
    : GUIFrame(frame)
{
#if wxUSE_STATUSBAR
    //statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
    //statusBar->SetStatusText(wxbuildinfo(short_f), 1);
#endif
}

ForexMathFrame::~ForexMathFrame()
{
}

void ForexMathFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void ForexMathFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void ForexMathFrame::OnHelp(wxCommandEvent &event)
{
    wxString msg = _("1. Enter all the required values and then leave the one in question empty. \nWhen you press calculate,the required value will be filled and highlighted.\n\n2. To calculate the margin,the only values you need are the #digits,lot size and current price.");
    wxMessageBox(msg, _("Help"));
}


void ForexMathFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = _("This app was developed by SK Mbatha\nwith the purpose of making forex risk calculations simpler by providing a feature where you can pre-calculate your losses before an order(not provided in Metatrader).\n\n To contact the developer,send an email to skatlego.mbatha@gmail.com");
    wxMessageBox(msg, _("About"));
}


void ForexMathFrame::OnClear(wxCommandEvent &event)
{
    ForexMathFrame::RefreshFields();

    t_Take_Profit->Clear();
    t_TP_SL->Clear();
    t_Current_Price->Clear();
    t_Lot->Clear();
    t_No_of_Digits->Clear();
    t_leverage->Clear();
    t_Margin->Clear();
}


void ForexMathFrame::OnCalculate(wxCommandEvent &event)
{
    int status=0;

    ///Refresh the field's colors
    ForexMathFrame::RefreshFields();

    ///Check if all the required fields are entered
    status+=CheckForInputEmptyError(t_Current_Price);
    //status+=CheckForInputEmptyError(t_Lot);
    status+=CheckForInputEmptyError(t_No_of_Digits);

    if(status>0)
    {
        wxBell();
        return;
    }


    status=0;
    ///Check if the values entered are numerals
    status+=ForexMathFrame::CheckForInputError(t_Take_Profit);
    status+=ForexMathFrame::CheckForInputError(t_TP_SL);
    status+=ForexMathFrame::CheckForInputError(t_Current_Price);
    status+=ForexMathFrame::CheckForInputError(t_Lot);
    status+=ForexMathFrame::CheckForInputError(t_No_of_Digits);
    status+=ForexMathFrame::CheckForInputError(t_leverage);
    //status+=ForexMathFrame::CheckForInputError(t_Margin);

    if(status>0)
    {
     wxString msg = _("Incorrect input.Only decimal numbers/integers can be computed!");
     wxMessageBox(msg, _("Error"));
     status=0;
     return;
    }

    /// If the above have passed,calculate the value required

    ///Check if there is an available field to compute
    if(ForexMathFrame::allFilled())
    {
        switch(last_entry)
        {
        case 0:t_TP_SL->Clear();
            break;
        case 1:t_Lot->Clear();
            break;
        case 2:t_Take_Profit->Clear();
            break;
        case 3:t_Margin->Clear();
            break;
        }

    }

    /// Get all the text control values and convert them into strings
    ForexMathFrame::getValues();

    if(isToggled)
    {
        if(v_TP_SL>0)
            v_TP_SL*=v_Current_Price;
        if(v_Margin>0)
            v_Margin*=v_Current_Price;
    }
    //-----------------------
    /// CALCULATE THE VALUES
    //-----------------------

    if(t_Take_Profit->GetValue().Cmp("")==0 || t_TP_SL->GetValue().Cmp("")==0 || t_Lot->GetValue().Cmp("")==0)
    {
    ///TAKE PROFIT OR STOP LOOS LINE
    if(t_Take_Profit->GetValue().Cmp("")==0 && v_TP_SL>0)
    {
        last_entry=2;
        double v2_TP_SL;
        v2_TP_SL=v_Current_Price+(v_TP_SL/(v_Lot*pow(10,v_No_of_Digits)));
        ForexMathFrame::answerShow(t_Take_Profit,(float)v2_TP_SL);
    }

    ///LOT
    else if(t_Lot->GetValue().Cmp("")==0 && v_Take_Profit>0 && v_TP_SL>0 )
    {
        last_entry=1;
        double result;
        result=v_TP_SL/((v_Take_Profit-v_Current_Price)*pow(10,v_No_of_Digits));
        ForexMathFrame::answerShow(t_Lot,(float)result);
    }

    ///Profit
    else if(t_TP_SL->GetValue().Cmp("")==0 && v_Take_Profit>0)
    {
        last_entry=0;
        double result;
        result=(v_Take_Profit-v_Current_Price)*pow(10,v_No_of_Digits)*v_Lot;

        if(!isToggled)
            ForexMathFrame::answerShow(t_TP_SL,(float)result);
        else
            ForexMathFrame::answerShow(t_TP_SL,(float)(result/v_Current_Price));
    }
    }

    ///MARGIN CALCULATIONS
    ForexMathFrame::getValues();///get the newly calculated values
    if(v_leverage>0)
    {
        double result;
        result=((v_Lot*v_Current_Price*pow(10,v_No_of_Digits))/v_leverage);

        if(!isToggled)
            ForexMathFrame::answerShow(t_Margin,(float)result);
        else
            ForexMathFrame::answerShow(t_Margin,(float)(result/v_Current_Price));
    }

    /// Clear all the values
       v_Take_Profit=0;
       v_TP_SL=0;
       v_Current_Price=0;
       v_Lot=0;
       v_No_of_Digits=0;
       v_leverage=0;
       v_Margin=0;
}


void ForexMathFrame::OnToggleCurrency(wxCommandEvent &event)
{
    if(!ForexMathFrame::isToggled)
    {
        isToggled=true;
        if(t_TP_SL->GetValue().Cmp("")!=0)
        {
            ForexMathFrame::getValues();
            t_TP_SL->SetValue(wxString::Format(wxT("%f"),v_TP_SL/v_Current_Price));
        }

        if(t_Margin->GetValue().Cmp("")!=0)
        {
            ForexMathFrame::getValues();
            t_Margin->SetValue(wxString::Format(wxT("%f"),v_Margin/v_Current_Price));
        }
    }
    else
    {
        isToggled=false;
        if(t_TP_SL->GetValue().Cmp("")!=0)
        {
            ForexMathFrame::getValues();
            t_TP_SL->SetValue(wxString::Format(wxT("%f"),v_TP_SL*v_Current_Price));
        }

        if(t_Margin->GetValue().Cmp("")!=0)
        {
            ForexMathFrame::getValues();
            t_Margin->SetValue(wxString::Format(wxT("%f"),v_Margin*v_Current_Price));
        }
    }

    wxWindow::Refresh();

}

///Additional helper functions

void ForexMathFrame::RefreshFields()
{
   wxColour *KatCostum=new wxColour(255,255,255);

   t_Take_Profit->SetBackgroundColour(*KatCostum);
   t_TP_SL->SetBackgroundColour(*KatCostum);
   t_Current_Price->SetBackgroundColour(*KatCostum);
   t_Lot->SetBackgroundColour(*KatCostum);
   t_No_of_Digits->SetBackgroundColour(*KatCostum);
   t_leverage->SetBackgroundColour(*KatCostum);
   t_Margin ->SetBackgroundColour(*KatCostum);
   wxWindow::Refresh();
}

int ForexMathFrame::CheckForInputError(wxTextCtrl* ptr)
{
    if(ptr->GetValue().GetChar(0)=='-')
    {
     return 0;
    }
    else if(ptr->GetValue().Cmp("")!=0 && ( ptr->GetValue().GetChar(0)<48 ||  ptr->GetValue().GetChar(0)>57 ))
    {
    wxColour *KatCostum=new wxColour(255,159,159);
    ptr->SetBackgroundColour(*KatCostum);
    wxWindow::Refresh();
    return 1;
    }

    return 0;
}

int ForexMathFrame::CheckForInputEmptyError(wxTextCtrl* ptr)
{
     if(ptr->GetValue().Cmp("")==0)
    {
        wxColour *KatCostum=new wxColour(255,159,159);
        ptr->SetBackgroundColour(*KatCostum);
        ptr->SetValue(_("??"));
        wxWindow::Refresh();
        return 1;
    }

    return 0;
}

///Show computed answer on the text control with a green highlight
void ForexMathFrame::answerShow(wxTextCtrl* ptr,float value)
{
        wxColour *KatCostum=new wxColour(71,219,90);
        ptr->SetBackgroundColour(*KatCostum);
        ptr->SetValue(wxString::Format(wxT("%f"),value));
        wxWindow::Refresh();
        return;
}

void ForexMathFrame::getValues()
{
    /// Get all the text control values and convert them into strings
    t_Take_Profit->GetValue().ToDouble(&v_Take_Profit);
    t_TP_SL->GetValue().ToDouble(&v_TP_SL);
    t_Current_Price->GetValue().ToDouble(&v_Current_Price);
    t_Lot->GetValue().ToDouble(&v_Lot);
    t_No_of_Digits->GetValue().ToDouble(&v_No_of_Digits);
    t_leverage->GetValue().ToDouble(&v_leverage);
    t_Margin->GetValue().ToDouble(&v_Margin);
    return;
}

bool ForexMathFrame::allFilled()
{
    if(t_Take_Profit->GetValue().Cmp("")==0)
        return false;
    else if(t_TP_SL->GetValue().Cmp("")==0)
        return false;
    else if(t_Current_Price->GetValue().Cmp("")==0)
        return false;
    else if(t_Lot->GetValue().Cmp("")==0)
        return false;
    else if(t_No_of_Digits->GetValue().Cmp("")==0)
        return false;
    else if (t_leverage->GetValue().Cmp("")==0)
        return false;
    else
        return true;
}



