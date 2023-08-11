//
// Created by Jack Xu on 8/4/23.
//

#include "Instance.h"
#include "G4RunManager.hh"
#include "G4UIManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include "G4SteppingVerbose.hh"
#include "Randomize.hh"
#include "INIReader.h"
#include "DetectorMaker.h"
#include "EventMaker.h"

Instance::Instance(path&& p, uint64_t _n, bool b): filepath{std::move(p)}, n{_n}, visualize(b) {
    INIReader ir(filepath);
    setupRandom();
    setupPrecision(4);
    initializeManagers();
    setupDetectorAndEvent(ir);

    ui = std::make_unique<SimpleUI>(visualize);
    ui->start();

    ui->ApplyCommand("/run/initialize");
}

void Instance::setupRandom() {
    CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
}

void Instance::setupPrecision(int i) {
    G4int precision = i;
    G4SteppingVerbose::UseBestUnit(precision);
}

void Instance::initializeManagers() {
    runManager = std::make_unique<G4RunManager>();
}

void Instance::setupDetectorAndEvent(INIReader& ir) {
    detector = DetectorMaker::makeDetector(ir, runManager.get());
    event = EventMaker::makeEvent(ir, runManager.get());

    detector->setEvent(event.get());
    event->setDetector(detector.get());
}

Instance::~Instance() {

}

void Instance::run() {
    ui->ApplyCommand("/run/beamOn " + std::to_string(n));
    std::cout << "Finished running " << n << " events.\n";
}

void Instance::saveResults() {
    throw std::runtime_error("Not implemented");
}