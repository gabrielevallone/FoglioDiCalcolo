//
// Created by vallons on 02/09/22.
//

#ifndef FOGLIODICALCOLO_OBSERVER_H
#define FOGLIODICALCOLO_OBSERVER_H

class Observer {
public:
    
    explicit Observer() = default;

    virtual ~Observer() = default;

    virtual void calculate() = 0;

};

#endif //FOGLIODICALCOLO_OBSERVER_H
