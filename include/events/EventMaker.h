//
// Created by Jack Xu on 8/4/23.
//

#ifndef CEVNS_SIM_EVENTMAKER_H
#define CEVNS_SIM_EVENTMAKER_H

#include "Event.h"

class EventMaker final {
private:
    constexpr static char field[] = "main";
    constexpr static char key[] = "event";
public:
    static std::shared_ptr<Event> makeEvent(INIReader&);
};

#endif //CEVNS_SIM_EVENTMAKER_H
