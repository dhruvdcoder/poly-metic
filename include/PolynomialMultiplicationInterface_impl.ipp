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
/** \file PolynomialMultiplication_impl.ipp 
 *  \brief Contains the implementation of * operator. Also contains the implementation of the function to select appropriate multiplication algorithm.
 */

#ifndef _POLYNOMIALMULTIPLICATIONINTERFACE_IMPL_IPP_
#define _POLYNOMIALMULTIPLICATIONINTERFACE_IMPL_IPP_

#include "../include/PolynomialMultiplicationInterface.hpp"
#include "../include/Polynomial.hpp"
#include "../include/PolynomialMultiplicationSimple.hpp"
#include <memory>
template<typename FieldT>
Polynomial<FieldT> operator*(const Polynomial<FieldT>& p1, const Polynomial<FieldT>& p2)
{
   // chose appropriate algo
   std::unique_ptr<PolynomialMultiplicationInterface<FieldT>> algo_interface = PolynomialMultiplicationInterface<FieldT>::getAppropriateAlgorithm(p1,p2);
   return algo_interface->multiply(p1,p2);
}

template<typename FieldT>
std::unique_ptr<PolynomialMultiplicationInterface<FieldT> > PolynomialMultiplicationInterface<FieldT>::getAppropriateAlgorithm( const Polynomial<FieldT>& p1, const Polynomial<FieldT>& p2)
{
   return std::make_unique<PolynomialMultiplicationSimple<FieldT>>();
}

#endif //_POLYNOMIALMULTIPLICATIONINTERFACE_IPP_
