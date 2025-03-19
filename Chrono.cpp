#include "wx_pch.h"
#include "Chrono.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(Chrono)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(Chrono)
//*)

//(*IdInit(Chrono)
const long Chrono::ID_STATICTEXT1 = wxNewId();
const long Chrono::ID_BUTTON1 = wxNewId();
const long Chrono::ID_BUTTON2 = wxNewId();
const long Chrono::ID_BUTTON3 = wxNewId();
const long Chrono::ID_PANEL1 = wxNewId();
const long Chrono::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Chrono,wxFrame)
	//(*EventTable(Chrono)
	//*)
END_EVENT_TABLE()

Chrono::Chrono(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Chrono)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("00 : 00 : 00"), wxDefaultPosition, wxSize(79,33), 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Démarrer"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("Arrêter"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(Panel1, ID_BUTTON3, _("Quitter"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer3->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	Timer1.SetOwner(this, ID_TIMER1);
	Timer1.Start(100, false);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Chrono::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Chrono::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Chrono::OnButton3Click);
	Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&Chrono::OnTimer1Trigger);
	//*)
}

Chrono::~Chrono()
{
	//(*Destroy(Chrono)
	//*)
}

void Chrono::OnTimer1Trigger(wxTimerEvent& event)
{
    if (rep == true)
        chrono.chronometrer();
    wxString mystring;
    mystring.Printf("%02d : %02d : %02d",chrono.donner_chrono_heure(), chrono.donner_chrono_min(),
                                    chrono.donner_chrono_sec() );
    StaticText1->SetLabel(mystring);
}

void Chrono::OnButton1Click(wxCommandEvent& event)
{
    chrono.chrono_a_zero();
    rep=true;
}

void Chrono::OnButton2Click(wxCommandEvent& event)
{
    rep=false;
}

void Chrono::OnButton3Click(wxCommandEvent& event)
{
    Close();
}
