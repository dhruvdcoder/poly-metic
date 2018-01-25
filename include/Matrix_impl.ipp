/*! @file Matrix_impl.ipp 
 * @brief Contains implementation of the template functions
 */
#ifndef _MATRIX_IMPL_IPP
#define _MATRIX_IMPL_IPP

#include "../include/Matrix.hpp" 
/**
 */
template <typename EntryT>
EntryT boost::numeric::ublas::trace(const Matrix<EntryT>& M)
{
   if (M.size1() != M.size2()) {
      throw std::invalid_argument("Matrix supplied to trace() is not square");
   }
   size_t n = M.size1(); 
   EntryT t {0};
   for (size_t i = 0; i < n ; ++i){
      t+=M(i,i);
   }
   return t;
}

#endif // _MATRIX_IMPL_H





