//
// Created by vallons on 02/09/22.
//

#include "Media.h"

Media::Media(FoglioDiCalcolo *s) : subjPtr(s) {
    subjPtr->addObserver(this);
}

Media::~Media() {
    subjPtr->removeObserver(this);
}

void Media::calculate() {

    double sum = 0;
    int count = 0;
    int i = 0;

    while (i < subjPtr->getNumOfCells()) {
        if (!subjPtr->getValues()[i].isEmpty) {
            sum = sum + subjPtr->getValues()[i].value;
            count++;
        }
        i++;
    }

//    for (int i = 0; i < 50; i++)
//        if (!subjPtr->getValues()[i].isEmpty) {
//            sum = sum + subjPtr->getValues()[i].value;
//            count++;
//        }

    if (count != 0) {
        double media = sum / count;
        wxString str = wxString::Format(wxT("%lf"), media);
        subjPtr->getResults()[1]->ChangeValue(str);
    } else
        subjPtr->getResults()[1]->ChangeValue(wxT("No values"));

}


