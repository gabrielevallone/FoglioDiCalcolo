//
// Created by vallons on 02/09/22.
//

#ifndef FOGLIODICALCOLO_MIN_H
#define FOGLIODICALCOLO_MIN_H

#include "Observer.h"
#include "FoglioDiCalcolo.h"

class Min : public Observer {
public:

    explicit Min(FoglioDiCalcolo *s);

    ~Min() override;

    void calculate() override;

private:

    FoglioDiCalcolo *subjPtr;

};


#endif //FOGLIODICALCOLO_MIN_H
