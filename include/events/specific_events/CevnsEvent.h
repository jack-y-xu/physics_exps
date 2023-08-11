//
// Created by Jack Xu on 7/13/23.
//

#ifndef CEVNS_SIM_CEVNSEVENT_H
#define CEVNS_SIM_CEVNSEVENT_H

#include <G4RunManager.hh>
#include "Event.h"
#include "INIReader.h"

class CevnsEvent: public Event {
public:
    CevnsEvent(INIReader &reader, G4RunManager *runManager);

    constexpr static char field[] = "cevns";

    CevnsEvent() = delete;
    explicit CevnsEvent(INIReader& reader);
    ~CevnsEvent() override;

    G4bool ProcessHits(G4Step*, G4TouchableHistory*) override;

    void exportToAnalysisManager() override;
private:
    G4int nPhotons;
};


#endif //CEVNS_SIM_CEVNSEVENT_H
