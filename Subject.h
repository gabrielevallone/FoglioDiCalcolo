//
// Created by vallons on 02/09/22.
//

#ifndef FOGLIODICALCOLO_SUBJECT_H
#define FOGLIODICALCOLO_SUBJECT_H

#include <wx/event.h>
#include "Observer.h"

class Subject {
public:

    virtual ~Subject() = default;

    virtual void addObserver(Observer *obs) = 0;

    virtual void removeObserver(Observer *obs) = 0;

    virtual void notify(wxCommandEvent &event) = 0;

};

#endif //FOGLIODICALCOLO_SUBJECT_H
