
#ifndef LP_COL_H
#define LP_COL_H

#include <string>

/**
  * class lp_col
  * 
  */

class lp_col
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  lp_col ( );

  /**
   * Empty Destructor
   */
  virtual ~lp_col ( );

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

  int j;
  char * name;
  lp_var_sign sign;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of j
   * @param new_var the new value of j
   */
  void setJ ( int new_var )   {
      j = new_var;
  }

  /**
   * Get the value of j
   * @return the value of j
   */
  int getJ ( )   {
    return j;
  }

  /**
   * Set the value of name
   * @param new_var the new value of name
   */
  void setName ( char * new_var )   {
      name = new_var;
  }

  /**
   * Get the value of name
   * @return the value of name
   */
  char * getName ( )   {
    return name;
  }

  /**
   * Set the value of sign
   * @param new_var the new value of sign
   */
  void setSign ( lp_var_sign new_var )   {
      sign = new_var;
  }

  /**
   * Get the value of sign
   * @return the value of sign
   */
  lp_var_sign getSign ( )   {
    return sign;
  }
private:


  void initAttributes ( ) ;

};

#endif // LP_COL_H
