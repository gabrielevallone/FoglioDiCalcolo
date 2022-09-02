//
// Created by vallons on 02/09/22.
//

#include "FoglioDiCalcolo.h"

void FoglioDiCalcolo::addObserver(Observer *obs) {
    observerList.push_back(obs);
}

void FoglioDiCalcolo::removeObserver(Observer *obs) {
    observerList.remove(obs);
}

void FoglioDiCalcolo::notify() {

}
