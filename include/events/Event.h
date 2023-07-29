//
// Created by Jack Xu on 7/7/23.
//

#ifndef CEVNS_SIM_EVENT_H
#define CEVNS_SIM_EVENT_H

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4VModularPhysicsList.hh"

#include "G4Step.hh"
#include "G4TouchableHistory.hh"


class Event {
public:
    virtual G4bool ProcessHits(G4Step*, G4TouchableHistory*) = 0;
    virtual void exportToAnalysisManager() = 0;

    G4VUserPrimaryGeneratorAction* getGenerator();
    G4VModularPhysicsList* getPhysics();
private:
    G4VUserPrimaryGeneratorAction* generator;
    G4VModularPhysicsList* physics;
};

#endif //CEVNS_SIM_EVENT_H
