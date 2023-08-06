//
// Created by Jack Xu on 7/28/23.
//

#include "GenericSD.h"

GenericSD::GenericSD(const G4String& name, Event* _event): G4VSensitiveDetector(name), event{_event} {};

G4bool GenericSD::ProcessHits(G4Step* step, G4TouchableHistory* history) {
    return event->ProcessHits(step, history);
};

Event* GenericSD::getEvent() {return event;};
