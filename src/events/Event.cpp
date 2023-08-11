//
// Created by Jack Xu on 7/7/23.
//

#include "Event.h"

G4VUserPrimaryGeneratorAction* Event::getGenerator() {
    if (!detector)
        throw std::runtime_error("You need to set the detector before you provide generator");
    return generator;
}

G4VModularPhysicsList* Event::getPhysics() {return physics;}

void Event::setDetector(Detector* _detector) {
    detector = _detector;
    generator->setDetector(_detector);
}

Event::~Event() {

};