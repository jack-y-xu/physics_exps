//
// Created by Jack Xu on 7/13/23.
//

#ifndef CEVNS_SIM_CEVNSEVENT_H
#define CEVNS_SIM_CEVNSEVENT_H

#include "Event.h"
#include "INIReader.h"

class CevnsEvent: public Event {

    CevnsEvent() = delete;
    CevnsEvent(INIReader& reader);
    ~CevnsEvent() override;

    void ProcessHits(G4Step*, G4TouchableHistory*) override;

    virtual void exportToAnalysisManager() = 0;
};

#endif //CEVNS_SIM_CEVNSEVENT_H
