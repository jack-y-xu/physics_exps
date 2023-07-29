//
// Created by Jack Xu on 7/14/23.
//

#include "MathUtils.h"

G4ThreeVector MathUtils::randomSample(const double bounds[3]) {
    return G4ThreeVector{G4UniformRand()*bounds[0], G4UniformRand()*bounds[1], G4UniformRand()*bounds[2]};
}

G4double MathUtils::random(double lower, double upper) {
    return (upper - lower) * G4UniformRand() + lower;
}