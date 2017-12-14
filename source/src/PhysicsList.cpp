#include "PhysicsList.hpp"
#include <G4Electron.hh>
#include <G4OpticalPhysics.hh>
#include <G4VUserPhysicsList.hh>

#include <G4Gamma.hh>
#include <G4Electron.hh>
#include <G4Positron.hh>
#include <G4Proton.hh>

void PhysicsList::ConstructParticle(){
    G4VModularPhysicsList::ConstructParticle();
    G4Electron::ElectronDefinition();
}

void PhysicsList::SetCuts(){
    SetCutsWithDefault();
}