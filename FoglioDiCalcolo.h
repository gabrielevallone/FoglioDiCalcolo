//
// Created by vallons on 02/09/22.
//

#ifndef FOGLIODICALCOLO_FOGLIODICALCOLO_H
#define FOGLIODICALCOLO_FOGLIODICALCOLO_H

#include "Subject.h"
#include <list>

class FoglioDiCalcolo : public Subject {
public:

    ~FoglioDiCalcolo() override;

    void addObserver(Observer *obs) override;

    void removeObserver(Observer *obs) override;

    void notify() override;

private:

    std::list<Observer *> observerList;
};


#endif //FOGLIODICALCOLO_FOGLIODICALCOLO_H
