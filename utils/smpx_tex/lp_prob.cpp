#include "lp_prob.h"

// Constructors/Destructors
//  

lp_prob::lp_prob ( ) {
initAttributes();
}

lp_prob::~lp_prob ( ) { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void lp_prob::initAttributes ( ) {
  m = -1;
  n = -1;
  valid_basis = false;
  tableau = 0;
  rows = 0;
  cols = 0;
}

