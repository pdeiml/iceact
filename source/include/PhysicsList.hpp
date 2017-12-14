#include <G4VModularPhysicsList.hh>
#include <G4EmStandardPhysics.hh>
#include <G4OpticalPhysics.hh>

class PhysicsList: public G4VModularPhysicsList {
public:
    /**
     * Constructor.
     *
     * @param verbose - the verbosity of the physics process (0).
     */
    virtual void ConstructParticle();
    virtual void SetCuts();
};