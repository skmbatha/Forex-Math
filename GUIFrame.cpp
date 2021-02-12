///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 481,380 ), wxSize( -1,380 ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_panel1 = new wxPanel( this, wxID_ANY, wxPoint( -1,-1 ), wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	m_panel1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVEBORDER ) );
	m_panel1->SetMaxSize( wxSize( -1,80 ) );

	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 1, 1, 0, 0 );

	m_staticText1 = new wxStaticText( m_panel1, wxID_ANY, wxT("Forex Math"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	m_staticText1->SetFont( wxFont( 36, 71, 90, 90, false, wxT("Showcard Gothic") ) );

	gSizer2->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );


	m_panel1->SetSizer( gSizer2 );
	m_panel1->Layout();
	gSizer2->Fit( m_panel1 );
	bSizer1->Add( m_panel1, 1, wxEXPAND | wxALL, 5 );

	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, wxEmptyString ), wxVERTICAL );

	m_panel4 = new wxPanel( sbSizer1->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 4, 4, 6, 0 );

	m_staticText2 = new wxStaticText( m_panel4, wxID_ANY, wxT("  SL/TP :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	gSizer1->Add( m_staticText2, 0, wxALL, 5 );

	t_Take_Profit = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 90,-1 ), 0 );
	t_Take_Profit->SetToolTip( wxT("Enter the Stop Loss or Take Profit amount.") );

	gSizer1->Add( t_Take_Profit, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticText3 = new wxStaticText( m_panel4, wxID_ANY, wxT("Profit/Loss :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	gSizer1->Add( m_staticText3, 0, wxALIGN_CENTER|wxALL, 5 );

	t_TP_SL = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 90,-1 ), 0 );
	t_TP_SL->SetToolTip( wxT("This is the expected profit/loss.") );

	gSizer1->Add( t_TP_SL, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText4 = new wxStaticText( m_panel4, wxID_ANY, wxT("  Current Price :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	gSizer1->Add( m_staticText4, 0, wxALL, 5 );

	t_Current_Price = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 90,-1 ), 0 );
	t_Current_Price->SetToolTip( wxT("Market current price.") );

	gSizer1->Add( t_Current_Price, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText5 = new wxStaticText( m_panel4, wxID_ANY, wxT("Lot size :      "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	gSizer1->Add( m_staticText5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	t_Lot = new wxTextCtrl( m_panel4, wxID_ANY, wxT("0.01"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	t_Lot->SetToolTip( wxT("Lot side where 1 lot = 100000 units") );

	gSizer1->Add( t_Lot, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText6 = new wxStaticText( m_panel4, wxID_ANY, wxT("  # Digits :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	gSizer1->Add( m_staticText6, 0, wxALL, 5 );

	t_No_of_Digits = new wxTextCtrl( m_panel4, wxID_ANY, wxT("5"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	t_No_of_Digits->SetToolTip( wxT("Number of digits after the comma on the price.") );

	gSizer1->Add( t_No_of_Digits, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText7 = new wxStaticText( m_panel4, wxID_ANY, wxT("Leverage 1:?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	gSizer1->Add( m_staticText7, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	t_leverage = new wxTextCtrl( m_panel4, wxID_ANY, wxT("500"), wxDefaultPosition, wxSize( 90,-1 ), 0 );
	t_leverage->SetToolTip( wxT("Right hand side of Leverage ratio.") );

	gSizer1->Add( t_leverage, 0, wxALIGN_CENTER|wxALL, 5 );

	m_staticText8 = new wxStaticText( m_panel4, wxID_ANY, wxT("  Margin :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	gSizer1->Add( m_staticText8, 0, wxALL, 5 );

	t_Margin = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 90,-1 ), 0 );
	t_Margin->SetToolTip( wxT("Minimum amount required to enter a trade.") );

	gSizer1->Add( t_Margin, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	gSizer1->Add( 0, 0, 1, wxEXPAND, 5 );


	m_panel4->SetSizer( gSizer1 );
	m_panel4->Layout();
	gSizer1->Fit( m_panel4 );
	sbSizer1->Add( m_panel4, 1, wxEXPAND | wxALL, 5 );


	m_panel2->SetSizer( sbSizer1 );
	m_panel2->Layout();
	sbSizer1->Fit( m_panel2 );
	bSizer1->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );

	Just_for_space = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	Just_for_space->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DDKSHADOW ) );
	Just_for_space->SetMaxSize( wxSize( -1,1 ) );

	bSizer1->Add( Just_for_space, 1, wxEXPAND | wxALL, 5 );

	m_panel5 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel5->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );

	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer( 1, 4, 0, 0 );


	gSizer4->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button3 = new wxButton( m_panel5, wxID_Calculate, wxT("Calculate"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_button3->SetDefault();
	gSizer4->Add( m_button3, 0, wxALL, 5 );

	m_toggleBtn1 = new wxToggleButton( m_panel5, wxID_ToggleCurrency, wxT("Toggle currency"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer4->Add( m_toggleBtn1, 0, wxALL, 5 );

	m_button4 = new wxButton( m_panel5, wxID_Clear, wxT("Clear"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	gSizer4->Add( m_button4, 0, wxALL, 5 );


	m_panel5->SetSizer( gSizer4 );
	m_panel5->Layout();
	gSizer4->Fit( m_panel5 );
	bSizer1->Add( m_panel5, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
    // Create a menu bar
    wxMenu *fileMenu = new wxMenu;
    wxMenu *helpMenu = new wxMenu;
    wxMenu *aboutMenu = new wxMenu;

    helpMenu->Append(wxID_HELP, wxT("&Help...\tF1"),wxT("Show how to use app."));
    fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-X"),wxT("Quit this program."));
    aboutMenu->Append(wxID_ABOUT, wxT("A&bout\tAlt-Y"),wxT("About the program."));
    // Now append the freshly created menu to the menu bar...
    m_menubar1 = new wxMenuBar();
    m_menubar1->Append(fileMenu, wxT("&File"));
    m_menubar1->Append(helpMenu, wxT("&Help"));
    m_menubar1->Append(aboutMenu, wxT("&About"));
    // ... and attach this menu bar to the frame
    SetMenuBar(m_menubar1);


	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );

}
