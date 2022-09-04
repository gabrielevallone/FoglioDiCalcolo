//
// Created by vallons on 02/09/22.
//

#include "Min.h"

Min::Min(FoglioDiCalcolo *s) : subjPtr(s) {
    subjPtr->addObserver(this);
}

Min::~Min() {
    subjPtr->removeObserver(this);
}

void Min::calculate() {

    double min = 0;
    bool b = true;
    int i = 0;

    while (i < subjPtr->getNumOfCells() && b) {
        if (!subjPtr->getValues()[i].isEmpty) {
            min = subjPtr->getValues()[i].value;
            b = false;
        }
        i++;
    }

    if (b)
        subjPtr->getResults()[3]->ChangeValue(wxT("No values"));

    else {
        while (i < subjPtr->getNumOfCells()) {

            if (!subjPtr->getValues()[i].isEmpty)
                if (subjPtr->getValues()[i].value < min)
                    min = subjPtr->getValues()[i].value;
            i++;
        }

        wxString str = wxString::Format(wxT("%lf"), min);
        subjPtr->getResults()[3]->ChangeValue(str);

    }

}


