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
/** \brief Polynomial and related classes
 */
#ifndef _POLYNOMIAL_HPP_
#define _POLYNOMIAL_HPP_

#include<list> // for doubly linked list
#include <initializer_list> // for init lists arguments
#ifdef INTRUSIVE_TESTS
#include "gtest/gtest.h"
#endif
#include <iostream>
#include <algorithm>

template<typename FieldT>
class PolynomialMultiplicationInterface;

/*! \class Polynomial
 *  \brief Template class used for polynomial.
 *  \tparam FieldT The field class. The field should support all arithmethic unary and binary operations with values 1 and 0 like, +1, *1, ==1,+0,*0,==0, etc.
 *
 *  @para Properties
 *    - Invariants 
 *       -# The last coefficent will always be non-zero.  
 */
template <typename FieldT>
class Polynomial
{

public:
   /*********** Constructors **************/
   /** \brief The default constructor to make the class default constructible
    */
   Polynomial():m_coefs(),m_size(0){}
   /** \brief Constructor to accept init list.
    */
   Polynomial(std::initializer_list<FieldT>);
   /** \brief Constructor to accept FieldT as input. Needed to support creation of a polynomial with zero degree.
    *  It also acts as implicit converting constructor
    */
   /** \brief Analogous to std containers, this constructor is provided to create a polynomial from any container which supports forward iterators. 
    */
   template <typename InputIt>
   Polynomial(InputIt first, InputIt last);

   Polynomial(FieldT c);
   /** \brief defaulted copy constructor .
    */
   template <typename convertibleToFieldT>
   Polynomial (convertibleToFieldT v);
   Polynomial(const Polynomial& rhs) 
      :m_coefs{rhs.m_coefs},m_size{rhs.m_size}
   {
      #ifdef VERBOSE
      std::cout<<"copy constructor Polynomial(const Polynomial&)"<<std::endl;
      #endif
   }
   /** \brief Move constructor implemented using swap
    */
   Polynomial(Polynomial&& rhs):Polynomial()
   {
      #ifdef VERBOSE
      std::cout<<"move constructor Polynomial(Polynomial&&)"<<std::endl;
      #endif
      swap(*this,rhs);
   }
   /** \brief Append new terms by pushing back coefficients */
   void appendTerm(FieldT coeff);
   
   /************** Operators *************/
   /** \brief Operator to fetch coefficients. Checks range.
    *  \except{Strong,The program is in a state as before the call}
    *  \param i Power of the x whose coefficient we want
    */
   const FieldT& operator[](size_t i) const;
   FieldT& operator[](size_t i) ;


   /** \brief A non-template friend swap to aid in the implementation of copy-and-swap
    *  \param [in] lhs LHS for the swap
    *  \param [in] rhs RHS for the swap
    *  \except{No throw}{The swap does not allocate any memory and hence should never throw}
    */
   friend void swap(Polynomial& lhs, Polynomial& rhs) noexcept
   {
      std::swap(lhs.m_coefs,rhs.m_coefs);
      std::swap(lhs.m_size,rhs.m_size);
   }


   /** \brief The assignemnt operator
    *  \param [in] RHS for the assignment
    */
   Polynomial const& operator=(const Polynomial& rhs);
    /** \brief The move assignemnt operator
    *  \param [in] RHS for the assignment
    */
   Polynomial const& operator=(Polynomial&& rhs);

  /** \brief The unary (-) operator */
   friend Polynomial operator-(Polynomial const& rhs) {
      #ifdef VERBOSE
      std::cout<<"friend -(const &)"<<std::endl;
      #endif
      Polynomial<FieldT> temp (rhs);
      temp.minus();
      return temp;
   }
   friend Polynomial operator-(Polynomial&& temp)  {
      #ifdef VERBOSE
      std::cout<<"friend -(&&)"<<std::endl;
      #endif
      temp.minus();
      return std::move(temp); /** \todo Find out why the move() is needed. RVO does not work on it own but has to be forced using move() here */
   }
   /** \brief The += operator for polynomials
    */
   const Polynomial& operator+=(Polynomial const& p2) ;
   /** \brief The += operator for polynomials
    */
   const Polynomial& operator+=(Polynomial&& p2) ;
   /** \brief The -= operator for polynomials
    */
   const Polynomial& operator-=(Polynomial const& p2) ;
   /** \brief The -= operator for polynomials using rvalue ref
    */
   const Polynomial& operator-=(Polynomial&& p2) ;

   /** \brief + operator
    */
   Polynomial operator+(const Polynomial& p2);
   Polynomial operator+(Polynomial p2) const;

   /** \brief - operator
    */
   Polynomial operator-(const Polynomial& p2);
   Polynomial operator-(Polynomial p2) const;

  
public: 
   /********** getters **********/
   size_t size() {return m_size;}
   size_t size() const {return m_size;}
   friend std::ostream& operator<< (std::ostream& os, const Polynomial& p) 
   {   
      size_t pow=0;
      os<<"(";
      std::for_each(p.m_coefs.begin(),p.m_coefs.end(), [&](const FieldT& coef) {os<< "+ "<<coef <<"x^"<<pow <<" ";++pow; });
      os<<")";
      return os; 
   }
private:
   /** \todo Use a general container instead of std::list as the choice of container would depend on
    * the algorithm class which is used for multiplication and addition.
    */
   std::list<FieldT> m_coefs; /*!< The list of coefficients */
   size_t m_size; /*!< Number of terms in the polynomial */

   /*********** Helpers ********/
   /** \brief Use to maintain the invariant 1
    */
   void trim();


   /** \brief Flip the sign of all coefs */
   Polynomial& minus();


   /************ Friend classes ************/
   friend class PolynomialMultiplicationInterface<FieldT>;

#ifdef INTRUSIVE_TESTS
public: 
   friend class PolynomialTest;
   FRIEND_TEST(PolynomialTest,helper_trim);
   FRIEND_TEST(PolynomialTest,helper_minus);
   friend class PolynomialTestMPZ;
   FRIEND_TEST(PolynomialMPZTest,helper_trim);
   FRIEND_TEST(PolynomialMPZTest,helper_minus);
#endif

};
//namespace PolynomialNS {
//   /*! \brief Brief function description here
//    * \param lhs lhs+=rhs
//    * \param rhs lhs+=rhs
//    */
//   template <typename FieldT>
//   FieldT& add_assign(FieldT& lhs,const FieldT& rhs) {
//      return lhs+=rhs;
//   }
//   /*! \brief Brief function description here
//    * \param lhs lhs-=rhs
//    * \param rhs lhs-=rhs
//    */
//   template <typename FieldT>
//   FieldT& subtract_assign(FieldT& lhs,const FieldT& rhs) {
//      return lhs-=rhs;
//   }
//}
template <typename T>
T minus(T v) {
   return -v;
}

/** \brief The multiplicaion operator. It picks the algorithm with which the Polynomial class is instantiated.
 */
template<typename FieldT>
Polynomial<FieldT> operator*(const Polynomial<FieldT>& p1, const Polynomial<FieldT>& p2);



#endif //_POLYNOMIAL_HPP_
