//
// Created by Jack Xu on 6/14/23.
//

#include "G4VUserDetectorConstruction.hh"
#include "Detector.h"

Detector::Detector(INIReader& reader) {
    init(reader);
}

Detector::~Detector() {
    delete builder;
}

