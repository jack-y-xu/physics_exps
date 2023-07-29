//
// Created by Jack Xu on 7/28/23.
//

#ifndef CEVNS_SIM_CEVNSGENERATOR_H
#define CEVNS_SIM_CEVNSGENERATOR_H

#include "G4VUserPrimaryGeneratorAction.hh"
#include "INIReader.h"

class CevnsGenerator: G4VUserPrimaryGeneratorAction {
    CevnsGenerator() = delete;
    CevnsGenerator(INIReader& reader);
    ~CevnsGenerator() override;

    void GeneratePrimaries(G4Event* anEvent) override;
};

#endif //CEVNS_SIM_CEVNSGENERATOR_H
