
#ifndef LP_ROW_H
#define LP_ROW_H

#include <string>

/**
  * class lp_row
  * 
  */

class lp_row
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  lp_row ( );

  /**
   * Empty Destructor
   */
  virtual ~lp_row ( );

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

  // ordinal number (1 to m) assigned to this row
  int i;
  // row name (1 to 255 chars); NULL means no name is assigned to this row
  char * name;
  lp_constr_sense_t constaint_sense;
  lp_aux_t auxiliary_type;
  numeric * row;
  bool obj_function;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of i
   * ordinal number (1 to m) assigned to this row
   * @param new_var the new value of i
   */
  void setI ( int new_var )   {
      i = new_var;
  }

  /**
   * Get the value of i
   * ordinal number (1 to m) assigned to this row
   * @return the value of i
   */
  int getI ( )   {
    return i;
  }

  /**
   * Set the value of name
   * row name (1 to 255 chars); NULL means no name is assigned to this row
   * @param new_var the new value of name
   */
  void setName ( char * new_var )   {
      name = new_var;
  }

  /**
   * Get the value of name
   * row name (1 to 255 chars); NULL means no name is assigned to this row
   * @return the value of name
   */
  char * getName ( )   {
    return name;
  }

  /**
   * Set the value of constaint_sense
   * @param new_var the new value of constaint_sense
   */
  void setConstaint_sense ( lp_constr_sense_t new_var )   {
      constaint_sense = new_var;
  }

  /**
   * Get the value of constaint_sense
   * @return the value of constaint_sense
   */
  lp_constr_sense_t getConstaint_sense ( )   {
    return constaint_sense;
  }

  /**
   * Set the value of auxiliary_type
   * @param new_var the new value of auxiliary_type
   */
  void setAuxiliary_type ( lp_aux_t new_var )   {
      auxiliary_type = new_var;
  }

  /**
   * Get the value of auxiliary_type
   * @return the value of auxiliary_type
   */
  lp_aux_t getAuxiliary_type ( )   {
    return auxiliary_type;
  }

  /**
   * Set the value of row
   * @param new_var the new value of row
   */
  void setRow ( numeric * new_var )   {
      row = new_var;
  }

  /**
   * Get the value of row
   * @return the value of row
   */
  numeric * getRow ( )   {
    return row;
  }

  /**
   * Set the value of obj_function
   * @param new_var the new value of obj_function
   */
  void setObj_function ( bool new_var )   {
      obj_function = new_var;
  }

  /**
   * Get the value of obj_function
   * @return the value of obj_function
   */
  bool getObj_function ( )   {
    return obj_function;
  }
private:


  void initAttributes ( ) ;

};

#endif // LP_ROW_H
