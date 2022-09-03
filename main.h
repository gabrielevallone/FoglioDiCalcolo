//
// Created by vallons on 03/09/22.
//

#ifndef FOGLIODICALCOLO_MAIN_H
#define FOGLIODICALCOLO_MAIN_H

#include <wx/wx.h>
#include "FoglioDiCalcolo.h"

class MyApp : public wxApp {
public:

    bool OnInit() override;

private:

    FoglioDiCalcolo *ptr;
};

#endif //FOGLIODICALCOLO_MAIN_H
