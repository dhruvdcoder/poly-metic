/** \brief Polynomial and related classes
 */
#ifndef _POLYNOMIAL_HPP_
#define _POLYNOMIAL_HPP_

#include<forward_list> // for signgly linked list
#include <initializer_list> // for init lists arguments

/*! \class Polynomial
 *  \brief Template class used for polynomial.
 *  \tparam FieldT The field class
 *
 *  Detailed description
 */
template <typename FieldT>
class Polynomial
{
public:
   /* Constructors */
   Polynomial(std::initializer_list<FieldT>);
   Polynomial(const Polynomial&) = delete; // deleted copy constructor till we figure out the behavior
   Polynomial(Polynomial&& )     = delete;
   
   /* Operators */
   /** \brief Operator to fetch coefficients. Checks range.
    *  \except{Strong,The program is in a state as before the call}
    *  \param i Power of the x whose coefficient we want
    */
   const FieldT& operator[](size_t i) const;
   FieldT& operator[](size_t i) ;

   

   
private:
   std::forward_list<FieldT> m_coefs; /*!< Member description */
   size_t m_size; /*!< Number of terms in the polynomial */
};

#endif //_POLYNOMIAL_HPP_
