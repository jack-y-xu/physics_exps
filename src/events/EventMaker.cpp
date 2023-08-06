//
// Created by Jack Xu on 8/4/23.
//

#include "EventMaker.h"
#include "CevnsEvent.h"

std::shared_ptr<Event> EventMaker::makeEvent(INIReader& ir) {
    std::string eventType = ir.GetString(field, key, "");

    if (eventType == CevnsEvent::field) {
        return std::make_shared<CevnsEvent>(ir);
    }
}