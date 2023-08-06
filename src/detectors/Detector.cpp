//
// Created by Jack Xu on 6/14/23.
//

#include "G4VUserDetectorConstruction.hh"
#include "Detector.h"

Detector::~Detector() {}

void Detector::setEvent(Event* _event) {
    event = _event;
}

