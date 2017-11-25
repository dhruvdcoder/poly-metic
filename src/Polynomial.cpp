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


/* Explicit instantiation */
template 
class Polynomial<double>;


