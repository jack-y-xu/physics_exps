//
// Created by Jack Xu on 7/13/23.
//

#ifndef CEVNS_SIM_GENERICSD_H
#define CEVNS_SIM_GENERICSD_H

#include "G4VSensitiveDetector.hh"

class Event;

class GenericSD: public G4VSensitiveDetector {
public:
    GenericSD(const G4String& name, Event* event);
    ~GenericSD() override = default;

    G4bool ProcessHits(G4Step* step, G4TouchableHistory* history) override;

    Event* getEvent();
private:
    Event* event;
};

#endif //CEVNS_SIM_GENERICSD_H
