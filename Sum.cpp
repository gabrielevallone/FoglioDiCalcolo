//
// Created by vallons on 02/09/22.
//

#include "Sum.h"

Sum::Sum(FoglioDiCalcolo *s) : subjPtr(s) {
    subjPtr->addObserver(this);
}

Sum::~Sum() {
    subjPtr->removeObserver(this);
}

void Sum::calculate() {

    double sum = 0;
    bool b = true;
    int i = 0;

    while (i < subjPtr->getNumOfCells()) {
        if (!subjPtr->getValues()[i].isEmpty) {
            sum = sum + subjPtr->getValues()[i].value;
            b = false;
        }
        i++;
    }

//    for (int i = 0; i < 50; i++)
//        if (!subjPtr->getValues()[i].isEmpty) {
//            sum = sum + subjPtr->getValues()[i].value;
//            b = false;
//        }

    if (b)
        subjPtr->getResults()[0]->ChangeValue(wxT("No values"));

    else {

        wxString str = wxString::Format(wxT("%lf"), sum);
        subjPtr->getResults()[0]->ChangeValue(str);

    }

}


