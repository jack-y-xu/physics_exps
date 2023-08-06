//
// Created by Jack Xu on 7/7/23.
//


#include "CevnsGenerator.h"

CevnsGenerator::CevnsGenerator(INIReader& reader) {

}

void CevnsGenerator::GeneratePrimaries(G4Event* anEvent) {

}

G4double CevnsGenerator::sampleTime() {
    return 0;
}


G4ThreeVector CevnsGenerator::samplePoint() {

}

CevnsGenerator::~CevnsGenerator() {

}

G4ThreeVector CevnsGenerator::sampleDirection() {
    return G4ThreeVector();
}

G4int CevnsGenerator::sampleNumber() {
    return 0;
}
