/*! @file Polynomial_testutils.ipp 
 * @brief Header for the utility functions like == operator for polynomials
 * */
#ifndef _POLYNOMIAL_TESTUTILS_IPP
#define _POLYNOMIAL_TESTUTILS_IPP

#include "../include/Polynomial.hpp" 
#include <limits>
template <typename FieldT>
 bool operator==(const Polynomial<FieldT>& lhs, const Polynomial<FieldT>& rhs)
{
   if (lhs.size() != rhs.size()) {
      return false;
   }
   for(size_t i = 0; i < lhs.size(); ++i){
      if (lhs[i] != rhs[i]) {
         return false;
      }
   }
   return true;
}



bool operator==(const Polynomial<double>& lhs, const Polynomial<double>& rhs)
{
   if (lhs.size() != rhs.size()) {
      return false;
   }
   auto areSame = [](double a, double b)->bool {
      return std::fabs(a-b) < std::numeric_limits<double>::epsilon();
   };
   for(size_t i = 0; i < lhs.size(); ++i){
      if (!areSame(lhs[i],rhs[i])) {
         return false;
      }
   }
   return true;

}
#endif // _POLYNOMIAL_TESTUTILS_H





