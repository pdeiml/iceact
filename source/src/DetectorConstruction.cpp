#include "DetectorConstruction.hpp"

#include "G4Box.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

G4VPhysicalVolume* DetectorConstruction::Construct(){
    G4Box* world = new G4Box("world", 1. * CLHEP::m, 1. * CLHEP::m, 1. * CLHEP::m);
    G4NistManager* vMaterialManager = G4NistManager::Instance();
    G4Material* air = vMaterialManager -> FindOrBuildMaterial("G4_AIR");
    G4LogicalVolume* worldLv = new G4LogicalVolume(world, air, "worldLv", NULL,
    NULL, NULL);
    G4VPhysicalVolume* worldPv = new G4PVPlacement(NULL, G4ThreeVector(), worldLv, "worldPv", NULL, false, 0, true);
    return worldPv;
}