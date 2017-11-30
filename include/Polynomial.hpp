/** \brief Polynomial and related classes
 */
#ifndef _POLYNOMIAL_HPP_
#define _POLYNOMIAL_HPP_

#include<list> // for doubly linked list
#include <initializer_list> // for init lists arguments
#ifdef INTRUSIVE_TESTS
#include "gtest/gtest.h"
#endif
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
   /** \brief defaulted copy constructor
    */
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
   Polynomial operator+(Polynomial p2);
   /** \brief + operator
    */
   Polynomial operator-(Polynomial p2);
public: 
   /********** getters **********/
   size_t size() {return m_size;}
   size_t size() const {return m_size;}
   
private:
   std::list<FieldT> m_coefs; /*!< The list of coefficients */
   size_t m_size; /*!< Number of terms in the polynomial */

   /*********** Helpers ********/
   /** \brief Use to maintain the invariant 1
    */
   void trim();


   /** \brief Flip the sign of all coefs */
   Polynomial& minus();

#ifdef INTRUSIVE_TESTS
public:
   friend class PolynomialTest;
   FRIEND_TEST(PolynomialTest,helper_trim);
   FRIEND_TEST(PolynomialTest,helper_minus);
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
#endif //_POLYNOMIAL_HPP_
