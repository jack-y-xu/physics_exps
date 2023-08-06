//
// Created by Jack Xu on 8/4/23.
//

#include "instance.h"
#include "G4RunManager.hh"
#include "G4UIManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include "G4SteppingVerbose.hh"
#include "Randomize.hh"
#include "INIReader.h"
#include "DetectorMaker.h"
#include "EventMaker.h"

Instance::Instance(path p, bool b): filepath{p}, visualize(b) {}

void Instance::setupRandom() {
    CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
}

void Instance::setupPrecision(int i) {
    G4int precision = i;
    G4SteppingVerbose::UseBestUnit(precision);
}

void Instance::initializeManagers() {
    runManager = std::make_unique<G4RunManager>();

    runManager->SetUserInitialization(detector.get());
    runManager->SetUserInitialization(event->getPhysics());
    runManager->SetUserAction(event->getGenerator());

}

void Instance::setupDetectorAndEvent(INIReader& ir) {
    detector = DetectorMaker::makeDetector(ir);
    event = EventMaker::makeEvent(ir);

    detector->setEvent(event.get());
    event->setDetector(detector.get());
}


Instance::~Instance() {

}

void Instance::run() {

    INIReader ir(filepath);
    setupRandom();
    setupPrecision(4);
    setupDetectorAndEvent(ir);
    initializeManagers();

}
