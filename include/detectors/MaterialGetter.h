//
// Created by Jack Xu on 7/13/23.
//

#ifndef CEVNS_SIM_MATERIALS_H
#define CEVNS_SIM_MATERIALS_H

#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4SDManager.hh"
#include "G4OpticalPhoton.hh"

class MaterialGetter {
public:
    static G4Material* liquidArgon();
    static G4Material* air();
    static G4Material* sipm();
    static G4Material* stainlessSteel();
};

#endif //CEVNS_SIM_MATERIALS_H
