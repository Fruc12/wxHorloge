/***************************************************************
 * Name:      wxHorlogeMain.h
 * Purpose:   Defines Application Frame
 * Author:    Fructueux ESSOU (narufruc@gmail.com)
 * Created:   2024-02-06
 * Copyright: Fructueux ESSOU ()
 * License:
 **************************************************************/

#ifndef WXHORLOGEMAIN_H
#define WXHORLOGEMAIN_H


//(*Headers(wxHorlogeFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/timer.h>
//*)
#include "horloge.h"

class wxHorlogeFrame: public wxFrame
{
    public:

        wxHorlogeFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxHorlogeFrame();
        Horloge horloge;

    private:

        //(*Handlers(wxHorlogeFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxHorlogeFrame)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_PANEL1;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(wxHorlogeFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStatusBar* StatusBar1;
        wxTimer Timer1;
        //*)

        DECLARE_EVENT_TABLE()
};


#endif // WXHORLOGEMAIN_H
