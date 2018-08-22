//   Copyright 2018 Dhruvesh Nikhilkumar Patel
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//
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




template <typename MatrixT>
bool boost::numeric::ublas::isSquare(const MatrixT& M)
{
   return (M.size1() == M.size2());
}
