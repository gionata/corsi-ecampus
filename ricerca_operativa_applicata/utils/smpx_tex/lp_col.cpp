#include "lp_col.h"

// Constructors/Destructors
//  

lp_col::lp_col ( ) {
initAttributes();
}

lp_col::~lp_col ( ) { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void lp_col::initAttributes ( ) {
  j = -1;
  name = 0;
}

