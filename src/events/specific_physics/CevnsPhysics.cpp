//
// Created by Jack Xu on 7/7/23.
//

#include "CevnsPhysics.h"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4OpticalPhysics.hh"

CevnsPhysics::CevnsPhysics() {
    RegisterPhysics(new G4OpticalPhysics());
}