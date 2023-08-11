//
// Created by Jack Xu on 7/29/23.
//

#ifndef CEVNS_SIM_GENERATOR_H
#define CEVNS_SIM_GENERATOR_H


#include "G4VUserPrimaryGeneratorAction.hh"
#include "Detector.h"


class Generator: public G4VUserPrimaryGeneratorAction {
public:
    void setDetector(Detector* detector);
protected:
    Detector* detector;
};

#endif //CEVNS_SIM_GENERATOR_H
