//
// Created by vallons on 02/09/22.
//

#ifndef FOGLIODICALCOLO_MEDIA_H
#define FOGLIODICALCOLO_MEDIA_H

#include "Observer.h"
#include "FoglioDiCalcolo.h"

class Media : public Observer {
public:

    explicit Media(FoglioDiCalcolo *s);

    ~Media() override;

    void calculate() override;

private:

    FoglioDiCalcolo *subjPtr;
};


#endif //FOGLIODICALCOLO_MEDIA_H
