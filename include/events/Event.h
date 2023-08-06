//
// Created by Jack Xu on 7/7/23.
//

#ifndef CEVNS_SIM_EVENT_H
#define CEVNS_SIM_EVENT_H

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4VModularPhysicsList.hh"

#include "G4Step.hh"
#include "G4TouchableHistory.hh"
#include "Detector.h"


class Event {
public:
    virtual ~Event();

    virtual G4bool ProcessHits(G4Step*, G4TouchableHistory*) = 0;
    virtual void exportToAnalysisManager() = 0;

    void setDetector(Detector*);

    G4VUserPrimaryGeneratorAction* getGenerator();
    G4VModularPhysicsList* getPhysics();
private:
    G4VUserPrimaryGeneratorAction* generator;
    G4VModularPhysicsList* physics;
    Detector* detector;
};

#endif //CEVNS_SIM_EVENT_H
