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
/** \brief Contains the definition for the abstract base class which will be used by different multiplication algorithms
 */
#ifndef _POLYNOMIALMULTIPLICATIONINTERFACE_HPP_
#define _POLYNOMIALMULTIPLICATIONINTERFACE_HPP_
#include <list>
#include <memory> ///< \todo for uniqe_ptr, can this be done using forward declaration ?
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

      /** \brief Algo picker */
      static std::unique_ptr<PolynomialMultiplicationInterface<FieldT>> getAppropriateAlgorithm(const Polynomial<FieldT>& p1, const Polynomial<FieldT>& p2);
};

#endif // _POLYNOMIALMULTIPLICATIONINTERFACE_HPP_

