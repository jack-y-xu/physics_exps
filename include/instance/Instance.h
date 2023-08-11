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
#include "SimpleUI.h"

using namespace std::filesystem;

class Instance final {
public:
    constexpr static char field[] = "main";

    Instance() = delete;
    Instance(path&&, uint64_t, bool);
    ~Instance();

    void run();

    void saveResults();
private:
    static void setupRandom();
    static void setupPrecision(int);
    void initializeManagers();
    void setupDetectorAndEvent(INIReader&);

    std::shared_ptr<Detector> detector;
    std::shared_ptr<Event> event;
    std::unique_ptr<G4RunManager> runManager;
    std::unique_ptr<SimpleUI> ui;

    path filepath;
    uint64_t n;
    bool visualize;

};

#endif //CEVNS_SIM_INSTANCE_H