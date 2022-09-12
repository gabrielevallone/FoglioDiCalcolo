//
// Created by vallons on 02/09/22.
//

#include "FoglioDiCalcolo.h"

FoglioDiCalcolo::FoglioDiCalcolo(const wxString &windowName, int maxNumCells) :
        wxFrame(nullptr, wxID_ANY, windowName, wxDefaultPosition, wxSize(720, 480)),
        numOfCells(maxNumCells), values(new cellValue[maxNumCells]) {

    for (int i = 0; i < numOfCells; i++) {
        values[i].value = 0;
        values[i].isEmpty = true;
    }

    Centre();
    SetMinSize(wxSize(480, 400));
    SetMaxSize(wxSize(860, 600));

    initializeWindow();

    Connect(wxEVT_TEXT, wxTextEventHandler(FoglioDiCalcolo::notify));

}

void FoglioDiCalcolo::addObserver(Observer *obs) {
    observerList.push_back(obs);
}

void FoglioDiCalcolo::removeObserver(Observer *obs) {
    observerList.remove(obs);
}

void FoglioDiCalcolo::notify(wxCommandEvent &event) {

    wxString s;
    for (int i = 0; i < numOfCells; i++) {

        if (cells[i]->GetValue() == wxEmptyString || cells[i]->GetValue() == wxT("-")) {
            values[i].value = 0;
            values[i].isEmpty = true;

        } else {
            s = cells[i]->GetValue();
            s.ToDouble(&values[i].value);
            values[i].isEmpty = false;
        }
    }

    for (const auto &it: observerList)
        it->calculate();

}

void FoglioDiCalcolo::initializeWindow() {

    boxSizer = new wxBoxSizer(wxVERTICAL);
    panel = new wxPanel(reinterpret_cast<wxWindow *>(this));
    gridSizer1 = new wxGridSizer(10, 5, 0, 0);

    cells.reserve(static_cast <unsigned long int> (numOfCells));

    for (int i = 0; i < numOfCells; i++) {
        cells.push_back(new wxTextCtrl(panel, wxID_EXECUTE, wxEmptyString, wxDefaultPosition, wxSize(140, 30), 0,
                                       wxTextValidator(wxFILTER_NUMERIC)));
        gridSizer1->Add(cells[i], 1, wxALIGN_LEFT);
    }

    gridSizer2 = new wxGridSizer(2, 4, 10, 10);

    sum = new wxStaticText(panel, wxID_ANY, wxT("Somma:"));
    media = new wxStaticText(panel, wxID_ANY, wxT("Media:"));
    max = new wxStaticText(panel, wxID_ANY, wxT("Max:"));
    min = new wxStaticText(panel, wxID_ANY, wxT("Min:"));

    gridSizer2->Add(sum, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(media, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(max, 1, wxALIGN_BOTTOM);
    gridSizer2->Add(min, 1, wxALIGN_BOTTOM);


    results.reserve(4);

    for (int i = 0; i < 4; i++) {
        results.push_back(new wxTextCtrl(panel, wxID_EXECUTE, wxEmptyString, wxDefaultPosition, wxSize(120, 30)));
        gridSizer2->Add(results[i], wxALIGN_BOTTOM);
    }

    boxSizer->Add(gridSizer1, 1, wxEXPAND);
    boxSizer->Add(gridSizer2, 1, wxEXPAND);

    panel->SetSizer(boxSizer);
}



FoglioDiCalcolo::~FoglioDiCalcolo() {

    delete[] values;

    for (int i = 0; i < numOfCells; i++)
        cells[i]->Destroy();
    cells.clear();

    for (int i = 0; i < 5; i++)
        results[i]->Destroy();
    results.clear();

    sum->Destroy();
    media->Destroy();
    max->Destroy();
    min->Destroy();

    panel->Destroy();

    observerList.clear();

}

const std::list<Observer *> &FoglioDiCalcolo::getObserverList() const {
    return observerList;
}

int FoglioDiCalcolo::getNumOfCells() const {
    return numOfCells;
}

cellValue *FoglioDiCalcolo::getValues() const {
    return values;
}

const std::vector<wxTextCtrl *> &FoglioDiCalcolo::getCells() const {
    return cells;
}

const std::vector<wxTextCtrl *> &FoglioDiCalcolo::getResults() const {
    return results;
}



