//
// Created by vallons on 02/09/22.
//

#include "Max.h"

Max::Max(FoglioDiCalcolo *s) : subjPtr(s) {
    subjPtr->addObserver(this);
}

Max::~Max() {
    subjPtr->removeObserver(this);
}

void Max::calculate() {

}


