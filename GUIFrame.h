///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFRAME_H__
#define __GUIFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/tglbtn.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_Calculate 1000
#define wxID_ToggleCurrency 1001
#define wxID_Clear 1002

///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel1;
		wxStaticText* m_staticText1;
		wxPanel* m_panel2;
		wxPanel* m_panel4;
		wxStaticText* m_staticText2;
		wxTextCtrl* t_Take_Profit;
		wxStaticText* m_staticText3;
		wxTextCtrl* t_TP_SL;
		wxStaticText* m_staticText4;
		wxTextCtrl* t_Current_Price;
		wxStaticText* m_staticText5;
		wxTextCtrl* t_Lot;
		wxStaticText* m_staticText6;
		wxTextCtrl* t_No_of_Digits;
		wxStaticText* m_staticText7;
		wxTextCtrl* t_leverage;
		wxStaticText* m_staticText8;
		wxTextCtrl* t_Margin;
		wxPanel* Just_for_space;
		wxPanel* m_panel5;
		wxButton* m_button3;
		wxToggleButton* m_toggleBtn1;
		wxButton* m_button4;
		wxMenuBar* m_menubar1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		
	
	public:
		
		GUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Forex Math by SK Mbatha"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 481,380 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~GUIFrame();
	
};

#endif //__GUIFRAME_H__
