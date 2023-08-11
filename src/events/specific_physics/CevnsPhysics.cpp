//
// Created by Jack Xu on 7/7/23.
//

#include "CevnsPhysics.h"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4OpticalPhysics.hh"
#include "G4VModularPhysicsList.hh"

CevnsPhysics::CevnsPhysics(): G4VModularPhysicsList() {
    RegisterPhysics(new G4OpticalPhysics());
    RegisterPhysics(new G4DecayPhysics());
    RegisterPhysics(new G4RadioactiveDecayPhysics());
}