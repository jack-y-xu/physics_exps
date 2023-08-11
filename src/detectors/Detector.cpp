//
// Created by Jack Xu on 6/14/23.
//

#include "G4VUserDetectorConstruction.hh"
#include "Detector.h"

Detector::~Detector() {}

G4VPhysicalVolume* Detector::Construct() {
    if (!event)
        throw std::runtime_error("You need to set the event before using detector");
    return _construct();
}

void Detector::setEvent(Event* _event) {
    event = _event;
}

