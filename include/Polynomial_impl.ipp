/**\file Polynomial_impl.ipp 
 * \brief Implementation of Polynomial template class. Does not include implementation of the * operator.
 */

#ifndef _POLYNOMIAL_IMPL_IPP_
#define _POLYNOMIAL_IMPL_IPP_

#include "../include/Polynomial.hpp"
#include <stdexcept>
#include <iterator>
#ifdef VERBOSE
#include <iostream>
#endif
/** 
 *  \param in_list Initializer list of coefficients. Starting with the x^0
 */
template <typename FieldT>
Polynomial<FieldT>::Polynomial(std::initializer_list<FieldT> in_list)
   :m_coefs{in_list},m_size{in_list.size()}
{
   trim();
}
/** 
 *  \param in_list Initializer list of coefficients. Starting with the x^0
 */
template <typename FieldT>
Polynomial<FieldT>::Polynomial(FieldT c)
   :m_coefs{c},m_size{1}
{
   trim();
}
/**
 *
 */
template<typename FieldT>
void Polynomial<FieldT>::appendTerm(FieldT coeff)
{
   m_coefs.push_back(coeff);
   ++m_size;
}
/**
 *
 */
template <typename FieldT>
const FieldT& Polynomial<FieldT>::operator[] (size_t i) const 
{
   if(i>=m_size){
      throw std::out_of_range("");
   }
   return *(std::next(m_coefs.begin(),i));
}

/**
 *
 */
template <typename FieldT>
FieldT& Polynomial<FieldT>::operator[] (size_t i) 
{
   /* calling the const version of the operator to avoid code duplication */
   return const_cast<FieldT&>((static_cast<Polynomial<FieldT> const*>(this)->operator[](i)));
}

/**
 *  We avoid explicit copying by passing the rhs by value. Hence the call to the copy constructor 
 *  and the copy operation become implicit.
 */
template <typename FieldT>
Polynomial<FieldT> const & Polynomial<FieldT>::operator=(const Polynomial<FieldT>& rhs_ref)
{
   #ifdef VERBOSE
   std::cout<<"=(&)"<<std::endl;
   #endif
   /* Provide self assignment protection if the use cases demand. Skipping for now.*/
   Polynomial<FieldT> rhs (rhs_ref);
   using std::swap; // Just incase we need ADL
   swap(*this,rhs);
   return *this;
  
}
/**
 *  
 *  */
template <typename FieldT>
Polynomial<FieldT> const& Polynomial<FieldT>::operator=(Polynomial<FieldT>&& rhs)
{
   /* Provide self assignment protection if the use cases demand. Skipping for now.*/
   #ifdef VERBOSE
   std::cout<<"=(&&)"<<std::endl;
   #endif

   using std::swap; // Just incase we need ADL
   swap(*this,rhs);
   return *this;
  
}




/** 
 * Implemented using copy-and-add in sequence. This is cleaner but a bit inefficient(possibly). Reconsider for performance optimization later. 
 * We cannot use implicit copying by using pass by value becuse RVO will not work on input argument of a function.
 * \todo Do away with the copying by using better approach.
 */
template <typename FieldT>
Polynomial<FieldT> const& Polynomial<FieldT>::operator+=(Polynomial<FieldT> const& p2)
{
   #ifdef VERBOSE
   std::cout<<"+=(&) "<<std::endl;
   #endif
   /* identify the polynomial which has higher degree*/
   Polynomial<FieldT> const& bigger_polynomial =  p2.size() > this->size() ? p2 : *this;
   Polynomial<FieldT> const& smaller_polynomial = p2.size() <= this->size() ? p2 : *this;
   /* copy the bigger polynomial */
   Polynomial<FieldT> copy_for_swap(bigger_polynomial);
   /* \todo Coefficient iterator class for Polynomial */
   auto s_it = smaller_polynomial.m_coefs.begin();
   auto b_it = copy_for_swap.m_coefs.begin();
   for( ;s_it != smaller_polynomial.m_coefs.end();) {
      *b_it+=*s_it; 
      ++s_it;
      ++b_it;
   } 
   /* ensure that the invariant is maintained */
   copy_for_swap.trim();
  /* swap this */
  swap(*this,copy_for_swap); 
  return *this;
}
/**
 */
template <typename FieldT>
Polynomial<FieldT> const& Polynomial<FieldT>::operator+=(Polynomial<FieldT>&& p2)
{
   #ifdef VERBOSE
   std::cout<<"+=(&&) "<<std::endl;
   #endif
   /* identify the polynomial which has higher degree*/
   Polynomial<FieldT>& bigger_polynomial =  p2.size() > this->size() ? p2 : *this;
   Polynomial<FieldT> const& smaller_polynomial = p2.size() <= this->size() ? p2 : *this;
   /* \todo Coefficient iterator class for Polynomial */
   auto s_it = smaller_polynomial.m_coefs.begin();
   auto b_it = bigger_polynomial.m_coefs.begin();
   for( ;s_it != smaller_polynomial.m_coefs.end();) {
      *b_it+=*s_it; 
      ++s_it;
      ++b_it;
   } 
   /* ensure that the invariant is maintained */
   bigger_polynomial.trim();
  /* swap this */
  swap(*this,bigger_polynomial); 
  return *this;
}
/** 
 * 
 * \todo Do away with the copying by using better approach.
 */
template <typename FieldT>
Polynomial<FieldT> const& Polynomial<FieldT>::operator-=(Polynomial<FieldT> const& p2)
{
   #ifdef VERBOSE
   std::cout<<"-=(&) "<<std::endl;
   #endif
   return (*this+=-p2);
}

/** 
 */
template <typename FieldT>
Polynomial<FieldT> const& Polynomial<FieldT>::operator-=(Polynomial<FieldT>&& p2)
{
   #ifdef VERBOSE
   std::cout<<"-=(&&) "<<std::endl;
   #endif

   return (*this+=-std::move(p2));
}

/**
 */
template <typename FieldT>
Polynomial<FieldT> Polynomial<FieldT>::operator+(Polynomial<FieldT> p2) const
{
   #ifdef VERBOSE
   std::cout<<"this+(value) "<<std::endl;
   #endif
   p2+=(*this);
   return std::move(p2);
}
/**
 */
template <typename FieldT>
Polynomial<FieldT> Polynomial<FieldT>::operator+(const Polynomial<FieldT>& p2) 
{
   return static_cast<const Polynomial<FieldT>*>(this)->operator+(p2);
}

/**
 */
template <typename FieldT>
Polynomial<FieldT> Polynomial<FieldT>::operator-(Polynomial<FieldT> p2) const 
{
   #ifdef VERBOSE
   std::cout<<"this-(value) "<<std::endl;
   #endif
   Polynomial<FieldT> temp (-std::move(p2));
   temp+=*this;
   return std::move(temp);
}

/**
 */
template <typename FieldT>
Polynomial<FieldT> Polynomial<FieldT>::operator-(const Polynomial<FieldT>& p2) 
{
   return static_cast<const Polynomial<FieldT>*>(this)->operator-(p2);
}
/******************* Helpers **********************/
template <typename FieldT>
void Polynomial<FieldT>::trim() 
{
   for(typename std::list<FieldT>::reverse_iterator r_it = m_coefs.rbegin(); r_it != m_coefs.rend(); ) {
      /* remove trailing zeros but if there is only one coefficient and that is zero then leave it to be a 
       * zero polynomial */
      if ( *r_it == 0 && size() >1) {
         typename std::list<FieldT>::reverse_iterator to_delete_it = r_it;
         ++r_it; // reverse iterator decremented
         m_coefs.erase(--to_delete_it.base()); //pre-decrement necessary as base points to an element ahead of rit which would be end() 
         m_size--;
      }
      else {
         break; // break as soon as we find first non-zero coeff from behind
      }
   }
}

template <typename FieldT>
Polynomial<FieldT>& Polynomial<FieldT>::minus() {
   for(auto& coef : m_coefs) {
      coef = ::minus(coef);
   }
   return *this;
}



#endif// _POLYNOMIAL_IPP_ 
