#ifndef REBOURS_H
#define REBOURS_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(Rebours)
	#include <wx/button.h>
	#include <wx/frame.h>
	#include <wx/panel.h>
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	#include <wx/timer.h>
	//*)
#endif
//(*Headers(Rebours)
//*)

#include "horloge.h"
class Rebours: public wxFrame
{
	public:

		Rebours(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Rebours();
		Rebour rebours;
		bool rep = false;
		unsigned int hh=0, mm=0, ss=0 ;

		//(*Declarations(Rebours)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		wxTimer Timer1;
		//*)

	protected:

		//(*Identifiers(Rebours)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL3;
		static const long ID_BUTTON1;
		static const long ID_BUTTON4;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_PANEL1;
		static const long ID_TIMER1;
		//*)

	private:

		//(*Handlers(Rebours)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void OnTimer1Trigger(wxTimerEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
