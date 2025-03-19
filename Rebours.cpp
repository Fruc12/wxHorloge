#include "wx_pch.h"
#include "Rebours.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(Rebours)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(Rebours)
//*)

//(*IdInit(Rebours)
const long Rebours::ID_STATICTEXT1 = wxNewId();
const long Rebours::ID_STATICTEXT2 = wxNewId();
const long Rebours::ID_TEXTCTRL1 = wxNewId();
const long Rebours::ID_STATICTEXT3 = wxNewId();
const long Rebours::ID_TEXTCTRL2 = wxNewId();
const long Rebours::ID_STATICTEXT4 = wxNewId();
const long Rebours::ID_TEXTCTRL3 = wxNewId();
const long Rebours::ID_BUTTON1 = wxNewId();
const long Rebours::ID_BUTTON4 = wxNewId();
const long Rebours::ID_BUTTON2 = wxNewId();
const long Rebours::ID_BUTTON3 = wxNewId();
const long Rebours::ID_PANEL1 = wxNewId();
const long Rebours::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Rebours,wxFrame)
	//(*EventTable(Rebours)
	//*)
END_EVENT_TABLE()

Rebours::Rebours(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Rebours)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("00 : 00 : 00"), wxDefaultPosition, wxSize(64,21), 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Définir durée :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("0"), wxDefaultPosition, wxSize(29,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer3->Add(TextCtrl1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _(":"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer3->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxSize(33,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl2->SetMaxLength(2);
	BoxSizer3->Add(TextCtrl2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _(":"), wxDefaultPosition, wxSize(4,16), 0, _T("ID_STATICTEXT4"));
	BoxSizer3->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, _("0"), wxDefaultPosition, wxSize(26,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl3->SetMaxLength(2);
	BoxSizer3->Add(TextCtrl3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Définir"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer4->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button4 = new wxButton(Panel1, ID_BUTTON4, _("Lancer"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer4->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("Arrêter"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer4->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(Panel1, ID_BUTTON3, _("Quitter"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer4->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	Timer1.SetOwner(this, ID_TIMER1);
	Timer1.Start(100, false);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Rebours::OnButton1Click);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Rebours::OnButton4Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Rebours::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Rebours::OnButton3Click);
	Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&Rebours::OnTimer1Trigger);
	//*)
}

Rebours::~Rebours()
{
	//(*Destroy(Rebours)
	//*)
}


void Rebours::OnButton1Click(wxCommandEvent& event)
{
    rep=false;
    wxString texte;
    texte = TextCtrl3->GetValue();
    if (!texte.ToUInt(&ss) || ss>=60 )
        wxMessageBox("Seconde comprise en 0 et 60 !");
    else
    {
        texte = TextCtrl2->GetValue();
        if (!texte.ToUInt(&mm) || mm>=60)
            wxMessageBox("Minute comprise entre 0 et 60 !");
        else
        {
            texte=TextCtrl1->GetValue();
            if (!texte.ToUInt(&hh))
            wxMessageBox("Heure positive !");
            else
            {
                texte.Printf("%02d : %02d : %02d", hh,mm,ss);
                StaticText1->SetLabel(texte);
                TextCtrl1->SetValue("0");
                TextCtrl2->SetValue("0");
                TextCtrl3->SetValue("0");
            }
        }
    }

}

void Rebours::OnButton3Click(wxCommandEvent& event)
{
    Close();
}

void Rebours::OnButton4Click(wxCommandEvent& event)
{
    rebours.rebour_a_zero();
    rep=true;
    wxString mystring;
    mystring.Printf("%02d : %02d : %02d" , hh , mm , ss );
    StaticText1->SetLabel(mystring);
}

void Rebours::OnTimer1Trigger(wxTimerEvent& event)
{
    if (rep == true)
    {
        rebours.decompter(hh,mm,ss);
        wxString mystring;
        mystring.Printf("%02d : %02d : %02d" , rebours.donner_rebours_heure(), rebours.donner_rebours_min(),
                                        rebours.donner_rebours_sec() );
        StaticText1->SetLabel(mystring);
        if ( rebours.donner_sec_ecoules() == 0 )
        {
            rep=false;
            wxMessageBox("TEMPS ECOULE !");
        }
    }
}

void Rebours::OnButton2Click(wxCommandEvent& event)
{
    rep=false;
    hh=mm=ss=0;
}
