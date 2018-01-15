/** \brief Contains the definition for the abstract base class which will be used by different multiplication algorithms
 */
#ifndef _POLYNOMIALMULTIPLICATIONINTERFACE_HPP_
#define _POLYNOMIALMULTIPLICATIONINTERFACE_HPP_
#include <list>
template <typename FieldT>
class Polynomial;


/** \brief The abstract base class, providing interface for all the polynomial multiplication algorithms
 */

template <typename FieldT>
class PolynomialMultiplicationInterface 
{
   private:

   protected:
      // Forward declaration
      // methods that provide interface to the data of Polynomial class. 
      virtual std::list<FieldT>& getPolynomialCoefficients(Polynomial<FieldT>& p){
         return p.m_coefs;
      }
      virtual const std::list<FieldT>& getPolynomialCoefficients(const Polynomial<FieldT>& p) {
         return p.m_coefs;
      }
   public:
      /** \brief The method which should be overloaded by the derived class to implement its own multiplication algorithm
       */
      virtual Polynomial<FieldT> multiply(const Polynomial<FieldT>& p1, const Polynomial<FieldT>& p2)=0;
};

#endif // _POLYNOMIALMULTIPLICATIONINTERFACE_HPP_

