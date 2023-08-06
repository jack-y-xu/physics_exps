//
// Created by Jack Xu on 7/13/23.
//
#include "CevnsEvent.h"

CevnsEvent::CevnsEvent(INIReader &reader) {
    nPhotons = reader.GetInteger();
}

CevnsEvent::~CevnsEvent() {
}

G4bool CevnsEvent::ProcessHits(G4Step *, G4TouchableHistory *) {
    return 0;
}

void CevnsEvent::exportToAnalysisManager() {

}

