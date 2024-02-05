#include "lp_row.h"

// Constructors/Destructors
//  

lp_row::lp_row ( ) {
initAttributes();
}

lp_row::~lp_row ( ) { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void lp_row::initAttributes ( ) {
  i = -1;
  name = 0;
  row = 0;
}

