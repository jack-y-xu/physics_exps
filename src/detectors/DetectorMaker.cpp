//
// Created by Jack Xu on 8/4/23.
//

#include "DetectorMaker.h"
#include "DuneFDDetector.h"
#include <memory>
#include "G4RunManager.hh"

#define DEBUG

std::shared_ptr<Detector> DetectorMaker::makeDetector(INIReader& ir, G4RunManager* runManager) {
    std::string detectorType = ir.GetString(field, key, "");
    if (detectorType == DuneFDDetector::field) {
        return std::make_shared<DuneFDDetector>(ir, runManager);
    }
    throw std::runtime_error("Invalid detector type " + detectorType);
}