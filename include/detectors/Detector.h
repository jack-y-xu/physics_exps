//
// Created by Jack Xu on 6/14/23.
//

#ifndef CEVNS_SIM_GEOMETRY_H
#define CEVNS_SIM_GEOMETRY_H

#include <G4ThreeVector.hh>
#include "INIReader.h"
#include "Event.h"
#include "GenericSD.h"

class G4VUserDetectorConstruction;

/* Abstract representation of a detector
 *
 * Comes with a builder, which Geant4 needs to construct the geometry
 * and setup hooks for when hits occur
 *
 * Detectors should not exist without events, because detectors will respond to
 * hits within the detector and what it logs depends on the event.
 */
class Detector: G4VUserDetectorConstruction {
public:
    Detector() = default;
    ~Detector() override;

    // No copy!
    Detector(const Detector& other) = delete;
    Detector& operator=(const Detector& other) = delete;

    virtual G4ThreeVector samplePoint() const = 0;
    virtual G4VPhysicalVolume* Construct() = 0;
private:
    GenericSD* gsd;
};

#endif //CEVNS_SIM_GEOMETRY_H
