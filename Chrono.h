#ifndef CHRONO_H
#define CHRONO_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(Chrono)
	#include <wx/button.h>
	#include <wx/frame.h>
	#include <wx/panel.h>
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/timer.h>
	//*)
#endif
//(*Headers(Chrono)
//*)

#include "horloge.h"

class Chrono: public wxFrame
{
	public:

		Chrono(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Chrono();
		Chronom chrono;
		bool rep=false;

		//(*Declarations(Chrono)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxTimer Timer1;
		//*)

	protected:

		//(*Identifiers(Chrono)
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_PANEL1;
		static const long ID_TIMER1;
		//*)

	private:
		//(*Handlers(Chrono)
		void OnButton3Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnTimer1Trigger(wxTimerEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
