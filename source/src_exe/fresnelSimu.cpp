#include <iostream>
#include <string>

#include <G4RunManager.hh>
#include <G4UImanager.hh>
#include <G4VisManager.hh>
#include <G4UIsession.hh>
#include <G4UIterminal.hh>

#include "DetectorConstruction.hpp"
#include "PhysicsList.hpp"

int main(int argc, char** argv){
    // Construct the run manager.
    G4RunManager* runManager = new G4RunManager();
    // Set mandatory initialization classes.
    runManager->SetUserInitialization(new DetectorConstruction());
    runManager->SetUserInitialization(new PhysicsList());

    runManager -> Initialize();

    G4UIsession* session = new G4UIterminal;
    session->SessionStart();
    delete session;
    delete runManager;
    return 0;

}