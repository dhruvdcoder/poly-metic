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
/*! @file MatrixAlgorithms_impl.ipp 
 * @brief Implements the template classes and functions in MatrixAlgorithms.hpp
 */
#ifndef _MATRIXALGORITHMS_IMPL_IPP
#define _MATRIXALGORITHMS_IMPL_IPP

#include "../include/MatrixAlgorithms.hpp"
#include <memory>
#include <stdexcept>
#include <vector>

namespace {
   template <typename MatrixT>
   MatrixT exp_by_squaring(const MatrixT& M,size_t n)
   {
        if (!isSquare(M)) {
           throw (std::invalid_argument("Input to exp_by_squaring is not a square matrix"));
        }
     switch(n) {
        case 0: {
                   throw (std::invalid_argument("exp_by_squaring: 0 is not a valid argument for exponent"));
                   //return Identity_Matrix<MatrixT::value_type>(n);
                }
        case 1: {
                   return MatrixT(M);
                }
        default:{
                   if (n%2 == 0) {//even
                      return exp_by_squaring<MatrixT>(prod(M,M), n/2);
                   }
                   else {// odd
                      return prod(M,exp_by_squaring<MatrixT>(prod(M,M),(n-1)/2));
                   }
                }
     }
   }

   template <typename MatrixT>
   typename MatrixT::value_type trace(const MatrixT& M, size_t n)
   {
     if (!isSquare(M)) {
        throw (std::invalid_argument("Input to exp_by_squaring is not a square matrix"));
     }
     std::unique_ptr<MatrixT> pB;
     std::unique_ptr<MatrixT> pA;

      /* divide M^n into two almost equal parts */
     if(n%2 ==0) {// even
        pB = std::make_unique<MatrixT>(exp(M,n/2));
        pA = std::make_unique<MatrixT>(trans(*pB)); ///< expecting two move operations. First 
                                                   // the output object of trans(B) is passed as rvalue ref
                                                   // to the move constructor of MatrixT and then move 
                                                   // assignment of unique_ptr is used to move the unique prt 
                                                   // to pA
        
     }
     else {
        pB = std::make_unique<MatrixT>(exp(M,(n-1)/2));
        pA = std::make_unique<MatrixT>(trans(prod(*pB,M))); // M^((n+1)/2)
     } 
     MatrixT R = element_prod(*pA,*pB);
     typename MatrixT::value_type tr=0;
     /** \todo remove direct reference to iterator1. Make is general. */
     for(typename MatrixT::iterator1 it1 = R.begin1(); it1 != R.end1(); ++it1) {
        for(typename MatrixT::iterator2 it2 = it1.begin(); it2 != it1.end(); ++it2){
           tr += *it2;
        }
     } 
     return tr;
   }
}
/** 
 *
 * Uses exponent by squaring 
 */
template <typename MatrixT>
MatrixT exp(const MatrixT& M, size_t n) 
{
   return exp_by_squaring(M,n);
}

/** 
 * \todo Cache the matrix exponentiation results. This will eleminate a lot of redundant computation.
 */
template <typename MatrixT>
typename MatrixT::value_type det(const MatrixT& M)
{
   if(!isSquare(M)) {
      throw (std::invalid_argument("Input to det is not a square matrix"));
   } 
   /* base */
   using valueT = typename MatrixT::value_type; 
   std::vector<valueT> invariants;
   std::vector<valueT> traces; ///< Contains tr(M^(i+1)) is i-th position
   size_t size = M.size1();
   invariants.reserve(size);
   traces.reserve(size);
   valueT temp = trace(M);
   invariants.push_back(temp);
   traces.push_back(temp);
   for(size_t k = 2; k <= size ; ++k) { // remember : k is 1 based but index of vector is 0 based
      /** \todo Make special arrangement when valueT is rational. This can be done using traits for the valueT*/
      valueT outer_multiplier = (k%2==0) ? (-1/double(k)) : (1/double(k));
      /* first inner term */
      traces.push_back(trace(M,k));
      /* second inner term */
      valueT sum = 0;
      for(size_t i =1 ;i<k;++i) {
         sum += (i%2==0) ? invariants[i-1]*traces[k-i-1] : invariants[i-1]*traces[k-i-1]*(valueT(-1));
      }
      invariants.push_back((traces[k-1] + sum)*(outer_multiplier));

   }
   return (valueT(invariants[size-1]));
}

   



#endif // _MATRIXALGORITHMS_H





