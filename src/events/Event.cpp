//
// Created by Jack Xu on 7/7/23.
//

#include "Event.h"

G4VUserPrimaryGeneratorAction* Event::getGenerator() {return generator;}

G4VModularPhysicsList* Event::getPhysics() {return physics;}