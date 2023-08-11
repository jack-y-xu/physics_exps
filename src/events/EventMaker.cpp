//
// Created by Jack Xu on 8/4/23.
//

#include "EventMaker.h"
#include "CevnsEvent.h"
#include "G4RunManager.hh"

std::shared_ptr<Event> EventMaker::makeEvent(INIReader& ir, G4RunManager* runManager) {
    std::string eventType = ir.GetString(field, key, "");

    if (eventType == CevnsEvent::field) {
        return std::make_shared<CevnsEvent>(ir, runManager);
    }

    throw std::runtime_error("Invalid event type " + eventType);
}