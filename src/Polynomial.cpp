/** \brief Implementation of Polynomial and related classes
 */
#include "../include/Polynomial.hpp"
#include <stdexcept>
#include <iterator>
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
Polynomial<FieldT> const & Polynomial<FieldT>::operator=(Polynomial<FieldT> rhs)
{
   /* Provide self assignment protection if the use cases demand. Skipping for now.*/
   using std::swap; // Just incase we need ADL
   swap(*this,rhs);
   return *this;
  
}

/** 
 * Implemented using copy-and-add in sequence. This is cleaner but a bit inefficient(possibly). Reconsider for performance optimization later. 
 * We cannot use implicit copying by using pass by value becuse RVO will not work on input argument of a function.
 */
template <typename FieldT>
Polynomial<FieldT> const& Polynomial<FieldT>::operator+=(Polynomial<FieldT> const& p2_copy)
{
   /* identify the polynomial which has higher degree*/
   
   
}




/******************* Helpers **********************/
template <typename FieldT>
void Polynomial<FieldT>::trim() 
{
   for(typename std::list<FieldT>::reverse_iterator r_it = m_coefs.rbegin(); r_it != m_coefs.rend(); ) {
      if ( *r_it == 0) {
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
/* Explicit instantiation */
template 
class Polynomial<double>;


