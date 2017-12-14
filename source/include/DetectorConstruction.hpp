#ifndef DETECTORCONSTRUCTION_HPP_
#define DETECTORCONSTRUCTION_HPP_

#include <G4VPhysicalVolume.hh>
#include <G4VUserDetectorConstruction.hh>

class DetectorConstruction : public G4VUserDetectorConstruction {
public:
DetectorConstruction() :
    G4VUserDetectorConstruction(){
}
    virtual G4VPhysicalVolume* Construct();
};

#endif // DETECTORCONSTRUCTION_HPP_