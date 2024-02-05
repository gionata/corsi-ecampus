#ifndef LP_SIMPLEX_H
#define LP_SIMPLEX_H

/**
  * class lp_simplex
  * 
  */

class lp_simplex
{
public:
  
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  lp_simplex();
  
  /**
   * Empty Destructor
   */
  virtual ~lp_simplex( );

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  


protected:

  // Static Protected attributes
  //  

  // Protected attributes
  //  

public:


  // Protected attribute accessor methods
  //  

protected:

public:


  // Protected attribute accessor methods
  //  

protected:


private:

  // Static Private attributes
  //  

  // Private attributes
  //  

  //! A valid basis has been found
  bool valid_basis;
  //! The current basis
  int *basis;
  //! The status of the simplex algorithm
  lp_status status;
};
#endif /* LP_SIMPLEX_H */
