// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4gsdetu.cc,v 2.0 1998/07/02 16:16:45 gunter Exp $
// GEANT4 tag $Name: geant4-00 $
//
#include "G3toG4.hh"

void PG4gsdetu(RWCString tokens[])
{
    // fill the parameter containers
    G3fillParams(tokens,PTgsdetu);

    // interpret the parameters
    G4String chset = Spar[0].data();
    G4String chdet = Spar[1].data();
    G4int nupar = Ipar[0];
    G4double *upar = Rpar;

    G4gsdetu(chset,chdet,nupar,upar);
}

void G4gsdetu(G4String chset, G4String chdet, G4int nupar, G4double upar[])
{
    // $$$ nothing right now
}