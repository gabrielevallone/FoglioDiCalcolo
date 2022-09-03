#include <iostream>
#include "main.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {

    ptr = new FoglioDiCalcolo(wxT("Foglio di Calcolo"));

    ptr->Show(true);

    return true;

}
