//
// Created by Jack Xu on 7/28/23.
//

#ifndef CEVNS_SIM_CEVNSGENERATOR_H
#define CEVNS_SIM_CEVNSGENERATOR_H

#include "G4ThreeVector.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "INIReader.h"
#include "G4Types.hh"
#include "Generator.h"

class CevnsGenerator: Generator {
public:
    CevnsGenerator() = delete;
    explicit CevnsGenerator(INIReader& reader);
    ~CevnsGenerator() override;

    void GeneratePrimaries(G4Event* anEvent) override;

private:

    G4double sampleTime();
    G4ThreeVector samplePoint();
    G4ThreeVector sampleDirection();
    G4int sampleNumber();
};

#endif //CEVNS_SIM_CEVNSGENERATOR_H
