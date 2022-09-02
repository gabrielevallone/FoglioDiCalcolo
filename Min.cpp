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

}


