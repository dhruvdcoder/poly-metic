/** \brief Simple O(n^2) field/ring operations algorithm for univariate polynomial multiplication */
#ifndef _POLYNOMIALMULTIPLICATIONSIMPLE_HPP_
#define _POLYNOMIALMULTIPLICATIONSIMPLE_HPP_

#include "../include/PolynomialMultiplicationInterface.hpp"

/** Simple O(n^2) field/ring operations algorithm for univariate polynomial multiplication
 */
template <typename FieldT>
class PolynomialMultiplicationSimple : public PolynomialMultiplicationInterface<FieldT>
{
   private:
   public: 
      PolynomialMultiplicationSimple()=default;
      virtual Polynomial<FieldT> multiply(const Polynomial<FieldT>& p1, const Polynomial<FieldT>& p2) override;
};

#endif // _POLYNOMIALMULTIPLICATIONSIMPLE_HPP_

