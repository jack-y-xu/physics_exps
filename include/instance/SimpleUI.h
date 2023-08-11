//
// Created by Jack Xu on 8/4/23.
//

#ifndef CEVNS_SIM_SIMPLEUI_H
#define CEVNS_SIM_SIMPLEUI_H

#include <memory>
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"

class SimpleUI final {

public:
    SimpleUI(bool);
    ~SimpleUI();

    void start();
    void ApplyCommand(std::string);
//    std::shared_ptr<G4UImanager> getCommandHandler();

private:
    std::shared_ptr<G4UImanager> uiManager;
    std::unique_ptr<G4VisManager> visManager;
    std::unique_ptr<G4UIExecutive> uiExecutive;

    bool visual = false;
};

#endif //CEVNS_SIM_SIMPLEUI_H
