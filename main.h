//
// Created by vallons on 03/09/22.
//

#ifndef FOGLIODICALCOLO_MAIN_H
#define FOGLIODICALCOLO_MAIN_H

#include <wx/wx.h>
#include "FoglioDiCalcolo.h"
#include "Sum.h"
#include "Media.h"
#include "Max.h"
#include "Min.h"

class MyApp : public wxApp {
public:

    bool OnInit() override;

private:

    FoglioDiCalcolo *ptr;

    Sum *sum;
    Media *media;
    Max *max;
    Min *min;

};

DECLARE_APP(MyApp)

#endif //FOGLIODICALCOLO_MAIN_H
