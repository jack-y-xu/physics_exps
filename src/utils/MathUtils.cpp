//
// Created by Jack Xu on 7/14/23.
//

#include "MathUtils.h"

G4double MathUtils::random(double lower, double upper) {
    return (upper - lower) * G4UniformRand() + lower;
}

G4ThreeVector MathUtils::randomPerpendicular(G4ThreeVector vec) {
    G4ThreeVector base = G4ThreeVector(1.0, 0.0, 0.0);
    G4ThreeVector ortho = vec.cross(base);
    if (ortho.mag() < 1e-9) {
        base = G4ThreeVector(0.0, 1.0, 0.0);
        ortho = vec.cross(base);
    }
    ortho = ortho.unit();
    return ortho;
}