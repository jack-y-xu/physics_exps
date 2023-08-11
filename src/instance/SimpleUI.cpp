//
// Created by Jack Xu on 8/4/23.
//

#include "SimpleUI.h"

SimpleUI::SimpleUI(bool visual): visual{visual} {};

void SimpleUI::start() {
    G4int argc = 1;
    char* argv[] = {"j_phys", nullptr};
    uiExecutive = std::make_unique<G4UIExecutive>(argc, argv);
    uiManager = std::shared_ptr<G4UImanager>(G4UImanager::GetUIpointer());

    if (visual) {
        visManager = std::make_unique<G4VisExecutive>();
        visManager->Initialize();
        uiExecutive->SessionStart();
        uiManager->ApplyCommand("/control/execute vis.mac");
    }
}

void SimpleUI::ApplyCommand(std::string str) {
    uiManager->ApplyCommand(str);
}