#include <iostream>
#include "main.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {

    ptr = new FoglioDiCalcolo(wxT("Foglio di Calcolo"));

    sum = new Sum(ptr);

    ptr->Show(true);

    return true;

}
