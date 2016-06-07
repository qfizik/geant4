// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4ParticleChangeForMSC.hh,v 2.1 1998/12/02 17:19:24 urban Exp $
// GEANT4 tag $ $
//
// 
// ------------------------------------------------------------
//	GEANT 4 class header file 
//
//	For information related to this code contact:
//	CERN, CN Division, ASD group
// 
// ------------------------------------------------------------
//   Implemented for the new scheme                 23 Mar. 1998  H.Kurahige
//
// -------------------------------------------------------------
#ifndef G4ParticleChangeForMSC_h
#define G4ParticleChangeForMSC_h 1

#include "globals.hh"
#include "G4ios.hh"
#include "G4ThreeVector.hh"
#include "G4ParticleMomentum.hh"
class G4DynamicParticle;
#include "G4VParticleChange.hh"

class G4ParticleChangeForMSC: public G4VParticleChange
{ 
  public:
    // default constructor
    G4ParticleChangeForMSC();

    // destructor
    virtual ~G4ParticleChangeForMSC();

  protected:
    // hide copy constructor and assignment operaor as protected
    G4ParticleChangeForMSC(const G4ParticleChangeForMSC &right);
    G4ParticleChangeForMSC & operator=(const G4ParticleChangeForMSC &right);


  public:
    // ----------------------------------------------------
    // --- the following methods are for updating G4Step -----   
    // Return the pointer to the G4Step after updating the Step information
    // by using final state information of the track given by a physics
    // process    
    virtual G4Step* UpdateStepForAlongStep(G4Step* Step);
    virtual G4Step* UpdateStepForAtRest(G4Step* Step);
    virtual G4Step* UpdateStepForPostStep(G4Step* Step);
    // A physics process gives the final state of the particle 
    // based on information of G4Track (or equivalently the PreStepPoint)
 
    virtual void Initialize(const G4Track&);
    // Initialize all propoerties by using G4Track information
       
    
    // ----------------------------------------------------
    //--- methods to keep information of the final state--
    //  IMPORTANT NOTE: Although the name of the class and methods are
    //   "Change", what it stores (and returns in get) are the "FINAL" 
    //   values of the Position, Momentum, etc.

    const G4ParticleMomentum* GetMomentumChange() const;
    void SetMomentumChange(G4double Px, G4double Py, G4double Pz);
    void SetMomentumChange(const G4ThreeVector& Pfinal);
    // Get/Set theMomentumChange vector: it is the final momentum direction.

    const G4ThreeVector* GetPositionChange() const;
    void SetPositionChange(G4double x, G4double y, G4double z);
    void SetPositionChange(const G4ThreeVector& finalPosition);
    //  Get/Set the final position of the current particle.

  public:
    virtual void DumpInfo() const;

  protected:
    G4ParticleMomentum theMomentumChange;
    //  It is the vector containing the final momentum direction
    //  after the invoked process. The application of the change
    //  of the momentum direction of the particle is not Done here.
    //  The responsibility to apply the change is up the entity
    //  which invoked the process.
    
    G4ThreeVector thePositionChange;
    //  The changed (final) position of a given particle.
    
};

#include "G4ParticleChangeForMSC.icc"

#endif

