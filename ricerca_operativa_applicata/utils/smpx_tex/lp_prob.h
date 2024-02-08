
#ifndef LP_PROB_H
#define LP_PROB_H

#include <string>
#include <vector>

/**
  * class lp_prob
  * 
  */

class lp_prob
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  lp_prob ( );

  /**
   * Empty Destructor
   */
  virtual ~lp_prob ( );

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

  //! Number of constraints - auxiliary variables
  int m;
  //! Number of structural (decisional) variables
  int n;
  //! The objective function coefficients
  lp_row * obj;
  //! The constaints rows
  lp_row * rows;
  //! The structural variables
  lp_col * cols;
  //! The direction: \min or \max?
  lp_dir_t direction;
  //! The constant term of the objective function
  numeric d;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of m
   * Number of constraints - auxiliary variables
   * @param new_var the new value of m
   */
  void setM ( int new_var )   {
      m = new_var;
  }

  /**
   * Get the value of m
   * Number of constraints - auxiliary variables
   * @return the value of m
   */
  int getM ( )   {
    return m;
  }

  /**
   * Set the value of n
   * Number of structural (decisional) variables
   * @param new_var the new value of n
   */
  void setN ( int new_var )   {
      n = new_var;
  }

  /**
   * Get the value of n
   * Number of structural (decisional) variables
   * @return the value of n
   */
  int getN ( )   {
    return n;
  }

  /**
   * Set the value of valid_basis
   * @param new_var the new value of valid_basis
   */
  void setValid_basis ( bool new_var )   {
      valid_basis = new_var;
  }

  /**
   * Get the value of valid_basis
   * @return the value of valid_basis
   */
  bool getValid_basis ( )   {
    return valid_basis;
  }

  /**
   * Set the value of basis
   * @param new_var the new value of basis
   */
  void setBasis ( vector<int> new_var )   {
      basis = new_var;
  }

  /**
   * Get the value of basis
   * @return the value of basis
   */
  vector<int> getBasis ( )   {
    return basis;
  }

  /**
   * Set the value of tableau
   * @param new_var the new value of tableau
   */
  void setTableau ( lp_tableau * new_var )   {
      tableau = new_var;
  }

  /**
   * Get the value of tableau
   * @return the value of tableau
   */
  lp_tableau * getTableau ( )   {
    return tableau;
  }

  /**
   * Set the value of rows
   * @param new_var the new value of rows
   */
  void setRows ( lp_row * new_var )   {
      rows = new_var;
  }

  /**
   * Get the value of rows
   * @return the value of rows
   */
  lp_row * getRows ( )   {
    return rows;
  }

  /**
   * Set the value of cols
   * @param new_var the new value of cols
   */
  void setCols ( lp_col * new_var )   {
      cols = new_var;
  }

  /**
   * Get the value of cols
   * @return the value of cols
   */
  lp_col * getCols ( )   {
    return cols;
  }

  /**
   * Set the value of direction
   * @param new_var the new value of direction
   */
  void setDirection ( lp_dir_t new_var )   {
      direction = new_var;
  }

  /**
   * Get the value of direction
   * @return the value of direction
   */
  lp_dir_t getDirection ( )   {
    return direction;
  }

  /**
   * Set the value of d
   * @param new_var the new value of d
   */
  void setD ( numeric new_var )   {
      d = new_var;
  }

  /**
   * Get the value of d
   * @return the value of d
   */
  numeric getD ( )   {
    return d;
  }

  /**
   * Set the value of status
   * @param new_var the new value of status
   */
  void setStatus ( lp_status new_var )   {
      status = new_var;
  }

  /**
   * Get the value of status
   * @return the value of status
   */
  lp_status getStatus ( )   {
    return status;
  }
private:


  void initAttributes ( ) ;

};

#endif // LP_PROB_H
