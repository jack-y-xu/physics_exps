//
// Created by Jack Xu on 7/13/23.
//

#ifndef CEVNS_SIM_MATHUTILS_H
#define CEVNS_SIM_MATHUTILS_H

#include <type_traits>
#include <concepts>
#include "Randomize.hh"
#include "G4ThreeVector.hh"
#include <random>

class MathUtils {
public:
    static G4double random(double lower, double upper);
    static G4ThreeVector randomPerpendicular(G4ThreeVector);
};

#endif //CEVNS_SIM_MATHUTILS_H
