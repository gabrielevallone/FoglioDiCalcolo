//
// Created by vallons on 02/09/22.
//

#ifndef FOGLIODICALCOLO_SUM_H
#define FOGLIODICALCOLO_SUM_H

#include "Observer.h"
#include "FoglioDiCalcolo.h"

class Sum : public Observer {
public:

    explicit Sum(FoglioDiCalcolo *s);

    ~Sum() override;

    void calculate() override;

private:

    FoglioDiCalcolo *subjPtr;

};


#endif //FOGLIODICALCOLO_SUM_H
