/*! @file Test_Polynomial.cpp 
 * @brief Contains the tests for the class Polynomial
 */
#include "../include/Polynomial.hpp"
#include "gtest/gtest.h"
#include <stdexcept>
#include <utility>

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
   TEST_F(PolynomialTest,constructor_copy){
      double c0=1,c1=2,c2=3;
      Polynomial<double> p {c0,c1,c2};
      Polynomial<double> f (p);
      ASSERT_DOUBLE_EQ(f[0],c0);
      ASSERT_DOUBLE_EQ(f[1],c1);
      ASSERT_DOUBLE_EQ(f[2],c2);

   }
   TEST_F(PolynomialTest,constructor_move){
      double c0=1,c1=2,c2=3;
      Polynomial<double> p {c0,c1,c2};
      Polynomial<double> f (std::move(p));
      ASSERT_DOUBLE_EQ(f[0],c0);
      ASSERT_DOUBLE_EQ(f[1],c1);
      ASSERT_DOUBLE_EQ(f[2],c2);
      /* That the moved from object is in expected state */
      ASSERT_EQ(p.size(),0);
   }
   TEST_F(PolynomialTest,access_operator_out_of_range_exception){
      double c0=1,c1=2,c2=3;
      Polynomial<double> f {c0,c1,c2};
      ASSERT_THROW(f[3],std::out_of_range);
   }

   TEST_F(PolynomialTest,friend_swap){
      double c0=1,c1=2,c2=3;
      double a0=4,a1=5,a2=6;
      Polynomial<double> fc {c0,c1,c2};
      Polynomial<double> fa {a0,a1,a2};
      swap(fc,fa);
      ASSERT_DOUBLE_EQ(fc[0],a0);
      ASSERT_DOUBLE_EQ(fc[1],a1);
      ASSERT_DOUBLE_EQ(fc[2],a2);
      ASSERT_DOUBLE_EQ(fa[0],c0);
      ASSERT_DOUBLE_EQ(fa[1],c1);
      ASSERT_DOUBLE_EQ(fa[2],c2);

   }

   TEST_F(PolynomialTest,helper_trim){
      double c0=1,c1=2,c2=3,c3=0;
      double a0=4,a1=0,a2=6,a3=0;
      Polynomial<double> fc {c0,c1,c2,c3};
      Polynomial<double> fa {a0,a1,a2,a3};
      ASSERT_EQ(fc.size(),3);
      ASSERT_EQ(fa.size(),3);
      ASSERT_DOUBLE_EQ(fc[0],c0);
      ASSERT_DOUBLE_EQ(fc[1],c1);
      ASSERT_DOUBLE_EQ(fc[2],c2);
      ASSERT_DOUBLE_EQ(fa[0],a0);
      ASSERT_DOUBLE_EQ(fa[1],a1);
      ASSERT_DOUBLE_EQ(fa[2],a2);

   }

}

int main(int argc,char **argv){
   ::testing::InitGoogleTest(&argc,argv);
   return RUN_ALL_TESTS();
}
