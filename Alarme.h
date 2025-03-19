#ifndef ALARME_H
#define ALARME_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(Alarme)
	#include <wx/button.h>
	#include <wx/frame.h>
	#include <wx/panel.h>
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	#include <wx/timer.h>
	//*)
#endif
//(*Headers(Alarme)
//*)


#include "horloge.h"
class Alarme: public wxFrame
{
	public:

		Alarme(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Alarme();
		Alarm alarm;
        int hh=0, mm=0;
        bool rep=false;

		//(*Declarations(Alarme)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTimer Timer1;
		//*)

	protected:

		//(*Identifiers(Alarme)
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON3;
		static const long ID_BUTTON2;
		static const long ID_PANEL1;
		static const long ID_TIMER1;
		//*)

	private:

		//(*Handlers(Alarme)
		void OnButton2Click(wxCommandEvent& event);
		void OnTimer1Trigger(wxTimerEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
