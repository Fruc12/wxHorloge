/***************************************************************
 * Name:      wxHorlogeMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Fructueux ESSOU (narufruc@gmail.com)
 * Created:   2024-02-06
 * Copyright: Fructueux ESSOU ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxHorlogeMain.h"
#include <wx/msgdlg.h>
#include "Chrono.h"
#include "Rebours.h"
#include "Alarme.h"

//(*InternalHeaders(wxHorlogeFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

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

//(*IdInit(wxHorlogeFrame)
const long wxHorlogeFrame::ID_STATICTEXT1 = wxNewId();
const long wxHorlogeFrame::ID_STATICTEXT2 = wxNewId();
const long wxHorlogeFrame::ID_BUTTON1 = wxNewId();
const long wxHorlogeFrame::ID_BUTTON2 = wxNewId();
const long wxHorlogeFrame::ID_BUTTON3 = wxNewId();
const long wxHorlogeFrame::ID_BUTTON4 = wxNewId();
const long wxHorlogeFrame::ID_PANEL1 = wxNewId();
const long wxHorlogeFrame::ID_MENUITEM1 = wxNewId();
const long wxHorlogeFrame::idMenuAbout = wxNewId();
const long wxHorlogeFrame::ID_STATUSBAR1 = wxNewId();
const long wxHorlogeFrame::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxHorlogeFrame,wxFrame)
    //(*EventTable(wxHorlogeFrame)
    //*)
END_EVENT_TABLE()

wxHorlogeFrame::wxHorlogeFrame(wxWindow* parent,wxWindowID id)
{

    //(*Initialize(wxHorlogeFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, wxEmptyString, wxDefaultPosition, wxSize(50,33), 0, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, wxEmptyString, wxDefaultPosition, wxSize(106,33), 0, _T("ID_STATICTEXT2"));
    BoxSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Alarme"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer3->Add(Button1, 1, wxALL, 5);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Compte à rebours"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer3->Add(Button2, 1, wxALL, 5);
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Chronomètre"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer3->Add(Button3, 1, wxALL, 5);
    Button4 = new wxButton(Panel1, ID_BUTTON4, _("Fermer"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer3->Add(Button4, 1, wxALL, 5);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(100, false);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxHorlogeFrame::OnButton1Click1);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxHorlogeFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxHorlogeFrame::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxHorlogeFrame::OnQuit);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxHorlogeFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxHorlogeFrame::OnAbout);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&wxHorlogeFrame::OnTimer1Trigger);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&wxHorlogeFrame::OnClose);
    //*)
}

wxHorlogeFrame::~wxHorlogeFrame()
{
    //(*Destroy(wxHorlogeFrame)
    //*)
}
void wxHorlogeFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxHorlogeFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));

}

void wxHorlogeFrame::OnClose(wxCloseEvent& event)
{
    event.Skip(TRUE);
}

void wxHorlogeFrame::OnButton1Click1(wxCommandEvent& event)
{
    Alarme* frm = new Alarme(this);
    frm->Show();
}

void wxHorlogeFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    horloge.definir_temps();
    wxString mystring;
    mystring.Printf( "%02d : %02d : %02d",
                    horloge.donner_heure(), horloge.donner_min(), horloge.donner_sec() );
    StaticText1->SetLabel(mystring);
    mystring.Printf( "%s %02d %s %d",horloge.donner_jr_sem(), horloge.donner_jr_mois(),
                    horloge.donner_mois(), horloge.donner_annee() );
    StaticText2->SetLabel(mystring);
}

void wxHorlogeFrame::OnButton3Click(wxCommandEvent& event)
{
    Chrono* frm = new Chrono(this);
    frm->Show();
}

void wxHorlogeFrame::OnButton2Click(wxCommandEvent& event)
{
    Rebours* frm = new Rebours(this);
    frm->Show();
}
