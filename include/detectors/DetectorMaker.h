//
// Created by Jack Xu on 8/4/23.
//

#ifndef CEVNS_SIM_DETECTORMAKER_H
#define CEVNS_SIM_DETECTORMAKER_H

#include <G4RunManager.hh>
#include "Detector.h"

class DetectorMaker {
    constexpr static char field[] = "main";
    constexpr static char key[] = "detector";
public:
    static std::shared_ptr<Detector> makeDetector(INIReader&);

    static std::shared_ptr<Detector> makeDetector(INIReader &ir, G4RunManager *runManager);
};

#endif //CEVNS_SIM_DETECTORMAKER_H
