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
    static G4ThreeVector randomSample(const double bounds[3]);
    static G4double random(double lower, double upper);
};

#endif //CEVNS_SIM_MATHUTILS_H
