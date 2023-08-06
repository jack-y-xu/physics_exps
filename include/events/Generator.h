//
// Created by Jack Xu on 7/29/23.
//

#ifndef CEVNS_SIM_GENERATOR_H
#define CEVNS_SIM_GENERATOR_H


#include "G4VUserPrimaryGeneratorAction.hh"
#include "Detector.h"

class Generator: G4VUserPrimaryGeneratorAction {
    void setDetector(Detector* detector);
private:
    Detector* detector;
};

#endif //CEVNS_SIM_GENERATOR_H
