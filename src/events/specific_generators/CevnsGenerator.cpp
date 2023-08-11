//
// Created by Jack Xu on 7/7/23.
//


#include <G4PrimaryVertex.hh>
#include <G4RandomDirection.hh>
#include <G4OpticalPhoton.hh>
#include "CevnsGenerator.h"
#include "MathUtils.h"
#include "G4SystemOfUnits.hh"
#include "G4Event.hh"

CevnsGenerator::CevnsGenerator(INIReader& ir) {
    nPhotons = ir.GetInteger64(field, "nPhotons", 0);
}

void CevnsGenerator::GeneratePrimaries(G4Event* anEvent) {

    if (!detector)
        throw std::runtime_error("You need to set the detector before running GeneratePrimaries!");

    G4double eventTime = sampleTime();

    const G4ThreeVector eventPosition = samplePoint();

    G4PrimaryVertex* vertex = new G4PrimaryVertex(eventPosition, eventTime);

    for (int i = 0; i < nPhotons; i++) {
        auto particle = new G4PrimaryParticle(G4OpticalPhoton::Definition());

        G4ThreeVector photonDirection = sampleDirection();
        G4ThreeVector photonPolarizationDirection = MathUtils::randomPerpendicular(photonDirection);
        G4double photonKineticEnergy = sampleEnergy();

        particle->SetMomentumDirection(photonDirection);
        particle->SetPolarization(photonPolarizationDirection);
        particle->SetKineticEnergy(photonKineticEnergy);

        vertex->SetPrimary(particle);
    }

    anEvent->AddPrimaryVertex(vertex);
}

G4double CevnsGenerator::sampleTime() {
    return 0;
}


G4ThreeVector CevnsGenerator::samplePoint() {
    return detector->samplePoint();
}

CevnsGenerator::~CevnsGenerator() {

}

G4double CevnsGenerator::sampleEnergy() {
    return 1 * MeV;
}

G4ThreeVector CevnsGenerator::sampleDirection() {
    return G4RandomDirection();
}

G4int CevnsGenerator::sampleNumber() {
    return 0;
}
