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

}


