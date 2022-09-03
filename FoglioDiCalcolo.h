//
// Created by vallons on 02/09/22.
//

#ifndef FOGLIODICALCOLO_FOGLIODICALCOLO_H
#define FOGLIODICALCOLO_FOGLIODICALCOLO_H

#include "Subject.h"
#include <list>
#include <wx/wx.h>
#include <vector>

struct cellValue {
    double value;
    bool isEmpty;
};

class FoglioDiCalcolo : public Subject {
public:

    ~FoglioDiCalcolo() override;

    void addObserver(Observer *obs) override;

    void removeObserver(Observer *obs) override;

    void notify() override;

    void initializeWindow();

private:

    std::list<Observer *> observerList;

    int numOfCells;
    cellValue *values;

    std::vector<wxTextCtrl *> cells;
    std::vector<wxTextCtrl *> results;

    wxStaticText *media;
    wxStaticText *max;
    wxStaticText *min;
    wxStaticText *sum;

    wxPanel *panel;
    wxBoxSizer *boxSizer;
    wxGridSizer *gridSizer1;
    wxGridSizer *gridSizer2;

};


#endif //FOGLIODICALCOLO_FOGLIODICALCOLO_H
