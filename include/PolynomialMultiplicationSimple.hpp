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

