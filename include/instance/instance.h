//
// Created by Jack Xu on 8/4/23.
//

#ifndef CEVNS_SIM_INSTANCE_H
#define CEVNS_SIM_INSTANCE_H

#include <filesystem>
#include "Detector.h"
#include "Event.h"
#include "G4RunManager.hh"
#include "G4UIManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include "G4SteppingVerbose.hh"
#include "Randomize.hh"

using namespace std::filesystem;

class Instance final {

    Instance() = delete;
    Instance(path, bool);
    ~Instance();

    void run();

    void saveResults();
private:

    void setupRandom();
    void setupPrecision(int);
    void initializeManagers();
    void setupDetectorAndEvent(INIReader&);
    path filepath;
    bool visualize;
    std::shared_ptr<Detector> detector;
    std::shared_ptr<Event> event;
    std::unique_ptr<G4RunManager> runManager;
    std::unique_ptr<G4VisManager> visManager;
    std::unique_ptr<G4UImanager> uiManager;
    std::unique_ptr<G4UIExecutive> uiExec;
};

#endif //CEVNS_SIM_INSTANCE_H
