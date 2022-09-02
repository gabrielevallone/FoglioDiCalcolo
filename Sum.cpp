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

}


