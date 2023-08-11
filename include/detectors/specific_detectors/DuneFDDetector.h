//
// Created by Jack Xu on 7/7/23.
//


#ifndef CEVNS_SIM_DUNEFDDETECTOR_H
#define CEVNS_SIM_DUNEFDDETECTOR_H

#include <G4PVPlacement.hh>
#include "G4SDManager.hh"
#include "G4VUserDetectorConstruction.hh"
#include "Event.h"
#include "GenericSD.h"
#include "Detector.h"
#include "G4Box.hh"
#include "G4RunManager.hh"

/* Builder (G4VUserDetectorConstruction) for the Dune FD Detector
 *
 * Responsible for telling geant4 how to build the geometry of FD, in addition to placing
 * the sensitive detectors.
 *
 * Initialized using an ini file and
 *
 */

class DuneFDDetector: public Detector {
public:

    constexpr static char field[] = "dunefd";
    // Constructor, destructors
    DuneFDDetector() = delete;
    DuneFDDetector(INIReader&, G4RunManager*);
    ~DuneFDDetector() override;

    [[nodiscard]] G4ThreeVector samplePoint() const override;

protected:
    G4VPhysicalVolume* _construct() override;

    G4Box *worldBox, *lArBox, *sdBox;
    G4LogicalVolume *worldLog, *lArLog, *sdLog;
    G4PVPlacement *worldPhys, *lArPhys, *sdPhys;

    double worldDim[3], argonDim[3], sdDim[3], sdPos[3];

    void placeWorld();
    void placeArgonBox();
    void placeSensitiveDetector();
};
#endif //CEVNS_SIM_DUNEFDDETECTOR_H
