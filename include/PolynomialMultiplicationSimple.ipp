/** \file PolynomialMultiplicationSimple.ipp
 *  \brief Contains implementation of the template class PolynomialMultiplicationSimple
 */
#ifndef _POLYNOMIALMULTIPLICATIONSIMPLE_IPP_
#define _POLYNOMIALMULTIPLICATIONSIMPLE_IPP_
#include "../include/PolynomialMultiplicationSimple.hpp"
#include "../include/Polynomial.hpp"
#include <algorithm>
#include <iterator>

template <typename FieldT>
Polynomial<FieldT> PolynomialMultiplicationSimple<FieldT>::multiply(const Polynomial<FieldT>& p1, const Polynomial<FieldT>& p2)
{
   Polynomial<FieldT> result;
   // result_deg = deg_p1 + deg_p2 = size_p1-1 + size_p2-1;
   // result_size = result_deg +1 = size_p1 + size_p2 - 1;
   // return if size_p1 or size_p2 is zero, ie, input is empty.
   if ((p1.size() ==0) || (p2.size() == 0)) {
      return result;
   }
   size_t result_size = p1.size() + p2.size() -1;
   // r_j = p_i * q_j-i ; i : 0 to j for j <= size_q
   // r_j = p_i * q_
   // ex: p = p0 p1 p2 p3 ; q= q0 q1 q2
   // r0 = p0*q0
   // r1 = p0*q1 + p1*q0
   // r2 = p0*q2 + p1*q1 + p2*q0
   // r3 = p0*q3 (ooops!) q3 does not exit 
   //
   // r0 = q0*p0
   // r1 = q0*p1 + q1*p0
   // r2 = q0*p2 + q1*p1 + q2*p0
   // r3 = q0*p3
   const std::list<FieldT>* pptr = &(this->getPolynomialCoefficients(p2));
   const std::list<FieldT>* qptr = &(this->getPolynomialCoefficients(p1));

   if (p1.size() >= p2.size()) {
      pptr = &(this->getPolynomialCoefficients(p1));
      qptr = &(this->getPolynomialCoefficients(p2));
   }
   const std::list<FieldT>& p = *pptr;
   const std::list<FieldT>& q = *qptr;
   size_t deg_p = p.size() -1;
   size_t deg_q = q.size() -1;
   auto convolve = [&](typename std::list<FieldT>::const_iterator q_begin, typename std::list<FieldT>::const_iterator q_end, typename std::list<FieldT>::const_iterator p_begin)
   {
      result.appendTerm(0);
      std::list<FieldT>& result_coeffs = this->getPolynomialCoefficients(result);
      auto rj_it = (result_coeffs).rbegin();
      for(;q_begin!=q_end;) {
         *rj_it += (*q_begin)*(*p_begin);
         p_begin--;
         q_begin++;
      }
   };

   typename std::list<FieldT>::const_iterator p_it_begin = p.begin();
   for(size_t j = 0; j < result_size; ++j) {
         if (j<=deg_p) {
         typename std::list<FieldT>::const_iterator q_it_begin = q.begin();
         typename std::list<FieldT>::const_iterator q_it_end = std::next(q.begin(), std::min(j,deg_q)+1); // next to last
         convolve(q_it_begin,q_it_end, p_it_begin);
         p_it_begin++;
      }
      else { //j > deg_p
         typename std::list<FieldT>::const_iterator q_it_begin = std::next(q.begin(),j-deg_p);
         typename std::list<FieldT>::const_iterator q_it_end = q.end(); // next to last
         p_it_begin = std::prev(p.end(),1);
         convolve(q_it_begin,q_it_end, p_it_begin);
      }
   }
   return result;

}


#endif // _POLYNOMIALMULTIPLICATIONSIMPLE_IPP_
 

