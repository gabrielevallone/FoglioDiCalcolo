#include <iostream>
#include "main.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {

    ptr = new FoglioDiCalcolo(wxT("Foglio di Calcolo"));

    sum = new Sum(ptr);
    media = new Media(ptr);
    max = new Max(ptr);
    min = new Min(ptr);

    ptr->Show(true);

    return true;

}
