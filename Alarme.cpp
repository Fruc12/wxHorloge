#include "wx_pch.h"
#include "Alarme.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(Alarme)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(Alarme)
//*)

//(*IdInit(Alarme)
const long Alarme::ID_TEXTCTRL1 = wxNewId();
const long Alarme::ID_STATICTEXT2 = wxNewId();
const long Alarme::ID_TEXTCTRL2 = wxNewId();
const long Alarme::ID_STATICTEXT1 = wxNewId();
const long Alarme::ID_BUTTON1 = wxNewId();
const long Alarme::ID_BUTTON3 = wxNewId();
const long Alarme::ID_BUTTON2 = wxNewId();
const long Alarme::ID_PANEL1 = wxNewId();
const long Alarme::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Alarme,wxFrame)
	//(*EventTable(Alarme)
	//*)
END_EVENT_TABLE()

Alarme::Alarme(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Alarme)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("0"), wxDefaultPosition, wxSize(26,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl1->SetMaxLength(2);
	BoxSizer4->Add(TextCtrl1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer4->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxSize(24,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl2->SetMaxLength(2);
	BoxSizer4->Add(TextCtrl2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, wxEmptyString, wxDefaultPosition, wxSize(58,15), 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Définir l\'alarme"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(Panel1, ID_BUTTON3, _("Supprimer"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer3->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("Quitter"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Alarme::OnButton1Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Alarme::OnButton3Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Alarme::OnButton2Click);
	Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&Alarme::OnTimer1Trigger);
	//*)
}

Alarme::~Alarme()
{
	//(*Destroy(Alarme)
	//*)
}


void Alarme::OnButton2Click(wxCommandEvent& event)
{
    Close();
}


void Alarme::OnTimer1Trigger(wxTimerEvent& event)
{
    if ( alarm.est_heure(hh,mm) && rep==true )
    {
        rep=false;
        wxString mystring;
        mystring.Printf("Il est l'heure : %02d : %02d", hh, mm);
        wxMessageBox(mystring);
    }
}

void Alarme::OnButton1Click(wxCommandEvent& event)
{
    wxString mystring;
    mystring = TextCtrl1->GetValue();
    if ( !mystring.ToInt(&hh) || hh>=24 || hh<0 )
        wxMessageBox("Heure comprise entre 0 et 24 !");
    else
    {
        mystring = TextCtrl2->GetValue();
        if ( !mystring.ToInt(&mm) || mm>=60 || mm<0 )
            wxMessageBox("Minute comprise entre 0 et 60 !");
        else
        {
            rep=true;
            mystring.Printf(  "%02d : %02d", hh, mm);
            StaticText1->SetLabel(mystring);
            TextCtrl1->SetValue("");
            TextCtrl2->SetValue("");
        }
    }
}

void Alarme::OnButton3Click(wxCommandEvent& event)
{
    rep=false;
    wxString mystring;
    mystring.Printf("");
    StaticText1->SetLabel(mystring);
}
