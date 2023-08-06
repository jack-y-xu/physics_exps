//
// Created by Jack Xu on 6/14/23.
//

#ifndef CEVNS_SIM_GEOMETRY_H
#define CEVNS_SIM_GEOMETRY_H

#include <G4ThreeVector.hh>
#include "INIReader.h"
#include "Event.h"
#include "GenericSD.h"
#include "G4VUserDetectorConstruction.hh"

/* Abstract representation of a detector
 *
 * Comes with a builder, which Geant4 needs to construct the geometry
 * and setup hooks for when hits occur
 *
 * Detectors should not exist without events, because detectors will respond to
 * hits within the detector and what it logs depends on the event.
 */
class Detector: public G4VUserDetectorConstruction {
public:
    Detector() = default;
    ~Detector() override;

    // No copy!
//    Detector(const Detector& other) = delete;
//    Detector& operator=(const Detector& other) = delete;

    void setEvent(Event* event);

    [[nodiscard]] virtual G4ThreeVector samplePoint() const = 0;
    G4VPhysicalVolume* Construct() override = 0;

protected:
    Event* event;
    GenericSD* gsd;
};

#endif //CEVNS_SIM_GEOMETRY_H
