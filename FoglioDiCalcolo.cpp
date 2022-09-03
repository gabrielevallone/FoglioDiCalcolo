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

void FoglioDiCalcolo::initializeWindow() {
    boxSizer = new wxBoxSizer(wxVERTICAL);
    panel = new wxPanel(reinterpret_cast<wxWindow *>(this));
    gridSizer1 = new wxGridSizer(10, 6, 0, 0);

    cells.reserve(static_cast <unsigned long int> (numOfCells));

    for (int i = 0; i < numOfCells; i++) {
        cells.push_back(new wxTextCtrl(panel, wxID_EXECUTE, wxEmptyString, wxDefaultPosition, wxSize(140, 30), 0,
                                       wxTextValidator(wxFILTER_NUMERIC)));
        gridSizer1->Add(cells[i], 1, wxALIGN_LEFT);
    }

    gridSizer2 = new wxGridSizer(2, 5, 10, 10);

    sum = new wxStaticText(panel, wxID_ANY, wxT("Somma:"));
    media = new wxStaticText(panel, wxID_ANY, wxT("Media:"));
    max = new wxStaticText(panel, wxID_ANY, wxT("Max:"));
    min = new wxStaticText(panel, wxID_ANY, wxT("Min:"));

    gridSizer2->Add(sum, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(media, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(max, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(min, 1, wxALIGN_BOTTOM);


    results.reserve(5);

    for (int i = 0; i < 5; i++) {
        results.push_back(new wxTextCtrl(panel, wxID_EXECUTE, wxEmptyString, wxDefaultPosition, wxSize(120, 30)));
        gridSizer2->Add(results[i], wxALIGN_BOTTOM);
    }

    boxSizer->Add(gridSizer1, 1, wxEXPAND);
    boxSizer->Add(gridSizer2, 1, wxEXPAND);

    panel->SetSizer(boxSizer);
}

FoglioDiCalcolo::~FoglioDiCalcolo() {

}

