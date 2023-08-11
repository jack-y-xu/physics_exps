//
// Created by Jack Xu on 7/13/23.
//
#include "CevnsEvent.h"
#include "CevnsGenerator.h"
#include "CevnsPhysics.h"
#include "G4RunManager.hh"

CevnsEvent::CevnsEvent(INIReader &reader, G4RunManager* runManager) {
    nPhotons = reader.GetInteger(field, "nPhotons", 0);

    physics = new CevnsPhysics();
    runManager->SetUserInitialization(physics);

    generator = new CevnsGenerator(reader);
    runManager->SetUserAction(generator);
}


CevnsEvent::~CevnsEvent() {
    // geant4 handles destruction of generator,
}

G4bool CevnsEvent::ProcessHits(G4Step *, G4TouchableHistory *) {
    return 0;
}

void CevnsEvent::exportToAnalysisManager() {

}

