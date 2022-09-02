//
// Created by vallons on 02/09/22.
//

#ifndef FOGLIODICALCOLO_MAX_H
#define FOGLIODICALCOLO_MAX_H

#include "Observer.h"
#include "FoglioDiCalcolo.h"

class Max : public Observer {
public:
    explicit Max(FoglioDiCalcolo *s);

    ~Max() override;

    void calculate() override;

private:

    FoglioDiCalcolo *subjPtr;
};


#endif //FOGLIODICALCOLO_MAX_H
