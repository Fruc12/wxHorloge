/***************************************************************
 * Name:      wxHorlogeApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Fructueux ESSOU (narufruc@gmail.com)
 * Created:   2024-02-06
 * Copyright: Fructueux ESSOU ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxHorlogeApp.h"

//(*AppHeaders
#include "wxHorlogeMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxHorlogeApp);

bool wxHorlogeApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxHorlogeFrame* Frame = new wxHorlogeFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;
}
