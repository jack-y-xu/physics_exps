//
// Created by Jack Xu on 7/7/23.
//

#include "DuneFDDetector.h"
#include "G4SystemOfUnits.hh"
#include "MaterialGetter.h"
#include "GenericSD.h"
#include "G4Event.hh"
#include <string>

DuneFDDetector::DuneFDDetector(INIReader& reader, Event* _event){
    static std::string dir[3] = {"X", "Y", "Z"};
    constexpr static char key[] = "dunefd";

    for (int i = 0; i < 3; i++) {
        worldDim[i] = reader.GetReal(key, "world" + dir[i], -1) * m;
        argonDim[i] = reader.GetReal(key, "argon" + dir[i], -1) * m;
        sdDim[i] = reader.GetReal(key, "slab" + dir[i], -1) * m;
        sdPos[i] = reader.GetReal(key, "slabPos" + dir[i], -1) * m;
    }

    gsd = new GenericSD(key, _event);
}

// geant4 manages the deletion of all objects we pass to it
DuneFDDetector::~DuneFDDetector() {

}

G4VPhysicalVolume* DuneFDDetector::Construct() {
    placeWorld();
    placeArgonBox();
    placeSensitiveDetector();
    return worldPhys;
}


/*
 * Samples a valid point within the liquid argon space
 */
G4ThreeVector DuneFDDetector::samplePoint() const {
    return G4ThreeVector(argonDim[0], argonDim[1], argonDim[2]);
}

void DuneFDDetector::placeWorld() {
    G4Material* stainlessSteel = MaterialGetter::stainlessSteel();
    G4Box* worldBox = new G4Box("worldBox", worldDim[0]/2, worldDim[1]/2, worldDim[2]/2);

    worldLog = new G4LogicalVolume(worldBox, stainlessSteel, "worldLog");
    worldPhys = new G4PVPlacement(0, G4ThreeVector(), worldLog, "worldPhys", 0, false, 0);
}

void DuneFDDetector::placeArgonBox() {
    G4Material* lAr = MaterialGetter::liquidArgon();
    G4Box* lArBox = new G4Box("lArBox", argonDim[0]/2, argonDim[1]/2, argonDim[2]/2);

    lArLog = new G4LogicalVolume(lArBox, lAr, "lArLog");
    lArPhys = new G4PVPlacement(0, G4ThreeVector(), lArLog, "lArPhys", worldLog, false, 0);
}

void DuneFDDetector::placeSensitiveDetector() {
    G4Material* sipm = MaterialGetter::sipm();

    G4Box* sdBox = new G4Box("sdBox", sdDim[0]/2, sdDim[1]/2, sdDim[2]/2);
    sdLog = new G4LogicalVolume(sdBox, sipm, "sdLog");
    sdPhys = new G4PVPlacement(0, G4ThreeVector(sdPos[0],sdPos[1],sdPos[2]), sdLog, "sdPhys", worldLog, false, 0);

    // Set the sensitive detector
    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    sdManager->AddNewDetector(gsd);
    sdLog->SetSensitiveDetector(gsd);
}

