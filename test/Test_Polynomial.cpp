/*! @file Test_Polynomial.cpp 
 * @brief Contains the tests for the class Polynomial
 */
#include "../include/Polynomial.hpp"
#include "gtest/gtest.h"
#include <stdexcept>

namespace{
   class PolynomialTest : public ::testing::Test{
      public:
      
      
     PolynomialTest(){
   
    }
    virtual ~PolynomialTest(){
       
    }
      protected:
         //virtual void SetUp() {

         //}

         //virtual void TearDown() {
            
         //}


   };


   TEST_F(PolynomialTest,constructor_init_list){
      double c0=1,c1=2,c2=3;
      Polynomial<double> f {c0,c1,c2};
      ASSERT_DOUBLE_EQ(f[0],c0);
      ASSERT_DOUBLE_EQ(f[1],c1);
      ASSERT_DOUBLE_EQ(f[2],c2);

   }
   TEST_F(PolynomialTest,access_operator_out_of_range_exception){
      double c0=1,c1=2,c2=3;
      Polynomial<double> f {c0,c1,c2};
      ASSERT_THROW(f[3],std::out_of_range);
   }


}

int main(int argc,char **argv){
   ::testing::InitGoogleTest(&argc,argv);
   return RUN_ALL_TESTS();
}
