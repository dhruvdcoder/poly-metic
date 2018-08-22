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
/*! @file Test_Polynomial_gmpz.cpp 
 * @brief Contains the tests for the class Polynomial with field type as "mpz_class" which is the integer class from GMP
 */
#include "../include/Polynomial.hpp"
#include "../include/gmpsupport.hpp"
#include "gtest/gtest.h"
#include <stdexcept>
#include <utility>


   class PolynomialMPZTest : public ::testing::Test{
      public:
      
      
     PolynomialMPZTest(){
   
    }
    virtual ~PolynomialMPZTest(){
       
    }
      protected:
         //virtual void SetUp() {

         //}

         //virtual void TearDown() {
            
         //}


   };


   TEST_F(PolynomialMPZTest,constructor_init_list){
      mpz_class c0=1,c1=2,c2=3;
      Polynomial<mpz_class> f {c0,c1,c2};
      ASSERT_EQ(f[0],c0);
      ASSERT_EQ(f[1],c1);
      ASSERT_EQ(f[2],c2);

   }
   TEST_F(PolynomialMPZTest,appendTerm){
      mpz_class c0=1,c1=2,c2=3;
      Polynomial<mpz_class> f;
      f.appendTerm(c0);
      f.appendTerm(c1);
      f.appendTerm(c2);
      ASSERT_EQ(f[0],c0);
      ASSERT_EQ(f[1],c1);
      ASSERT_EQ(f[2],c2);

   }
   TEST_F(PolynomialMPZTest,constructor_copy){
      mpz_class c0=1,c1=2,c2=3;
      Polynomial<mpz_class> p {c0,c1,c2};
      Polynomial<mpz_class> f (p);
      ASSERT_EQ(f[0],c0);
      ASSERT_EQ(f[1],c1);
      ASSERT_EQ(f[2],c2);

   }
   TEST_F(PolynomialMPZTest,constructor_move){
      mpz_class c0=1,c1=2,c2=3;
      Polynomial<mpz_class> p {c0,c1,c2};
      Polynomial<mpz_class> f (std::move(p));
      ASSERT_EQ(f[0],c0);
      ASSERT_EQ(f[1],c1);
      ASSERT_EQ(f[2],c2);
      /* That the moved from object is in expected state */
      ASSERT_EQ(p.size(),0);
   }
   TEST_F(PolynomialMPZTest,assignment_move){
      mpz_class c0=1,c1=2,c2=3;
      Polynomial<mpz_class> p {c0,c1,c2};
      Polynomial<mpz_class> f;
      f=std::move(p);
      ASSERT_EQ(f[0],c0);
      ASSERT_EQ(f[1],c1);
      ASSERT_EQ(f[2],c2);
      /* That the moved from object is in expected state */
      ASSERT_EQ(p.size(),0);
   }
   TEST_F(PolynomialMPZTest,access_operator_out_of_range_exception){
      mpz_class c0=1,c1=2,c2=3;
      Polynomial<mpz_class> f {c0,c1,c2};
      ASSERT_THROW(f[3],std::out_of_range);
   }

   TEST_F(PolynomialMPZTest,friend_swap){
      mpz_class c0=1,c1=2,c2=3;
      mpz_class a0=4,a1=5,a2=6;
      Polynomial<mpz_class> fc {c0,c1,c2};
      Polynomial<mpz_class> fa {a0,a1,a2};
      swap(fc,fa);
      ASSERT_EQ(fc[0],a0);
      ASSERT_EQ(fc[1],a1);
      ASSERT_EQ(fc[2],a2);
      ASSERT_EQ(fa[0],c0);
      ASSERT_EQ(fa[1],c1);
      ASSERT_EQ(fa[2],c2);

   }

   TEST_F(PolynomialMPZTest,helper_trim){
      mpz_class c0=1,c1=2,c2=3,c3=0;
      mpz_class a0=4,a1=0,a2=6,a3=0;
      Polynomial<mpz_class> fc {c0,c1,c2,c3};
      Polynomial<mpz_class> fa {a0,a1,a2,a3};
      ASSERT_EQ(fc.size(),3);
      ASSERT_EQ(fa.size(),3);
      ASSERT_EQ(fc[0],c0);
      ASSERT_EQ(fc[1],c1);
      ASSERT_EQ(fc[2],c2);
      ASSERT_EQ(fa[0],a0);
      ASSERT_EQ(fa[1],a1);
      ASSERT_EQ(fa[2],a2);

   }

   TEST_F(PolynomialMPZTest,sum_assign_operator){
      mpz_class c0=1,c1=2,c2=3,c3=0;
      mpz_class a0=4,a1=0,a2=6,a3=10;
      Polynomial<mpz_class> fc {c0,c1,c2,c3};
      Polynomial<mpz_class> fa {a0,a1,a2,a3};
      
      fc+=fa;
      ASSERT_EQ(fc.size(),4);
      ASSERT_EQ(fa.size(),4);
      
      ASSERT_EQ(fc[0],c0+a0);
      ASSERT_EQ(fc[1],c1+a1);
      ASSERT_EQ(fc[2],c2+a2);
      ASSERT_EQ(fc[3],c3+a3);
      ASSERT_EQ(fa[0],a0);
      ASSERT_EQ(fa[1],a1);
      ASSERT_EQ(fa[2],a2);
      ASSERT_EQ(fa[3],a3);


   }
   TEST_F(PolynomialMPZTest,sum_assign_operator_rvalue_ref){
      mpz_class c0=1,c1=2,c2=3,c3=0;
      mpz_class a0=4,a1=0,a2=6,a3=10;
      Polynomial<mpz_class> fc {c0,c1,c2,c3};
      
      fc+=(Polynomial<mpz_class> {a0,a1,a2,a3});
      ASSERT_EQ(fc.size(),4);
      
      ASSERT_EQ(fc[0],c0+a0);
      ASSERT_EQ(fc[1],c1+a1);
      ASSERT_EQ(fc[2],c2+a2);
      ASSERT_EQ(fc[3],c3+a3);

   }
   TEST_F(PolynomialMPZTest,subtract_assign_operator){
      mpz_class c0=1,c1=2,c2=3,c3=0;
      mpz_class a0=4,a1=0,a2=6,a3=10;
      Polynomial<mpz_class> fc {c0,c1,c2,c3};
      Polynomial<mpz_class> fa {a0,a1,a2,a3};
      
      fc-=fa;
      ASSERT_EQ(fc.size(),4);
      ASSERT_EQ(fa.size(),4);
      
      ASSERT_EQ(fc[0],c0-a0);
      ASSERT_EQ(fc[1],c1-a1);
      ASSERT_EQ(fc[2],c2-a2);
      ASSERT_EQ(fc[3],c3-a3);
      ASSERT_EQ(fa[0],a0);
      ASSERT_EQ(fa[1],a1);
      ASSERT_EQ(fa[2],a2);
      ASSERT_EQ(fa[3],a3);


   }
   TEST_F(PolynomialMPZTest,subtract_assign_operator_rvalue_ref){
      mpz_class c0=1,c1=2,c2=3,c3=0;
      mpz_class a0=4,a1=0,a2=6,a3=10;
      Polynomial<mpz_class> fc {c0,c1,c2,c3};
      
      fc-=(Polynomial<mpz_class> {a0,a1,a2,a3});
      ASSERT_EQ(fc.size(),4);
      
      ASSERT_EQ(fc[0],c0-a0);
      ASSERT_EQ(fc[1],c1-a1);
      ASSERT_EQ(fc[2],c2-a2);
      ASSERT_EQ(fc[3],c3-a3);

   }
   TEST_F(PolynomialMPZTest,unary_minus_operator_rvalue){
      mpz_class a0=4,a1=0,a2=6,a3=10;
      Polynomial<mpz_class> fa =-(Polynomial<mpz_class> {a0,a1,a2,a3});
      
      ASSERT_EQ(fa[0],-a0);
      ASSERT_EQ(fa[1],-a1);
      ASSERT_EQ(fa[2],-a2);
      ASSERT_EQ(fa[3],-a3);
   }
   TEST_F(PolynomialMPZTest,unary_minus_operator){
      mpz_class a0=4,a1=0,a2=6,a3=10;
      Polynomial<mpz_class> fa {a0,a1,a2,a3};
      Polynomial<mpz_class> f =-fa;
      
      ASSERT_EQ(f[0],-a0);
      ASSERT_EQ(f[1],-a1);
      ASSERT_EQ(f[2],-a2);
      ASSERT_EQ(f[3],-a3);
   }
   TEST_F(PolynomialMPZTest,helper_minus){
      mpz_class a0=4,a1=0,a2=6,a3=10;
      Polynomial<mpz_class> fa {a0,a1,a2,a3};
      fa.minus();
      ASSERT_EQ(fa.size(),4);
      
      ASSERT_EQ(fa[0],-a0);
      ASSERT_EQ(fa[1],-a1);
      ASSERT_EQ(fa[2],-a2);
      ASSERT_EQ(fa[3],-a3);


   }
   TEST_F(PolynomialMPZTest,add_operator){
      mpz_class c0=1,c1=2,c2=3,c3=0;
      mpz_class a0=4,a1=0,a2=6,a3=10;
      Polynomial<mpz_class> fc {c0,c1,c2,c3};
      Polynomial<mpz_class> fa {a0,a1,a2,a3};
      
      Polynomial<mpz_class> f=fa+fc;
      ASSERT_EQ(fc.size(),3);
      ASSERT_EQ(fa.size(),4);
      ASSERT_EQ(f.size(),4);

      
      ASSERT_EQ(f[0],c0+a0);
      ASSERT_EQ(f[1],c1+a1);
      ASSERT_EQ(f[2],c2+a2);
      ASSERT_EQ(f[3],c3+a3);
      ASSERT_EQ(fa[0],a0);
      ASSERT_EQ(fa[1],a1);
      ASSERT_EQ(fa[2],a2);
      ASSERT_EQ(fa[3],a3);
      ASSERT_EQ(fc[0],c0);
      ASSERT_EQ(fc[1],c1);
      ASSERT_EQ(fc[2],c2);

   }
   TEST_F(PolynomialMPZTest,add_operator_rvalue){
      mpz_class c0=1,c1=2,c2=3,c3=0;
      mpz_class a0=4,a1=0,a2=6,a3=10;
      
      Polynomial<mpz_class> fa {a0,a1,a2,a3};
      
      Polynomial<mpz_class> f=fa+(Polynomial<mpz_class> {c0,c1,c2,c3});
      ASSERT_EQ(fa.size(),4);
      ASSERT_EQ(f.size(),4);

      
      ASSERT_EQ(f[0],c0+a0);
      ASSERT_EQ(f[1],c1+a1);
      ASSERT_EQ(f[2],c2+a2);
      ASSERT_EQ(f[3],c3+a3);
      ASSERT_EQ(fa[0],a0);
      ASSERT_EQ(fa[1],a1);
      ASSERT_EQ(fa[2],a2);
      ASSERT_EQ(fa[3],a3);

   }
   TEST_F(PolynomialMPZTest,subtract_operator){
      mpz_class c0=1,c1=2,c2=3,c3=10;
      mpz_class a0=4,a1=0,a2=6,a3=10;
      Polynomial<mpz_class> fc {c0,c1,c2,c3};
      Polynomial<mpz_class> fa {a0,a1,a2,a3};
      
      Polynomial<mpz_class> f=fa-fc;
      ASSERT_EQ(fc.size(),4);
      ASSERT_EQ(fa.size(),4);
      ASSERT_EQ(f.size(),3);

      
      ASSERT_EQ(f[0],a0-c0);
      ASSERT_EQ(f[1],a1-c1);
      ASSERT_EQ(f[2],a2-c2);
      ASSERT_EQ(fa[0],a0);
      ASSERT_EQ(fa[1],a1);
      ASSERT_EQ(fa[2],a2);
      ASSERT_EQ(fa[3],a3);
      ASSERT_EQ(fc[0],c0);
      ASSERT_EQ(fc[1],c1);
      ASSERT_EQ(fc[2],c2);

   }


   TEST_F(PolynomialMPZTest,multiply_operator){
      mpz_class c0=1,c1=2,c2=3,c3=4;
      mpz_class a0=4,a1=0,a2=6;
      Polynomial<mpz_class> fc {c0,c1,c2,c3};
      Polynomial<mpz_class> fa {a0,a1,a2};
      
      Polynomial<mpz_class> f=fa*fc;
      ASSERT_EQ(f.size(),6);

      
      ASSERT_EQ(f[0],c0*a0);
      ASSERT_EQ(f[1],a0*c1+a1*c0);
      ASSERT_EQ(f[2],a0*c2+a1*c1+a2*c0);
      ASSERT_EQ(f[3],a0*c3+a1*c2+a2*c1);
      ASSERT_EQ(f[4],a1*c3+a2*c2);
      ASSERT_EQ(f[5],a2*c3);

      Polynomial<mpz_class> g=fa*fc;
      ASSERT_EQ(g.size(),6);

      
      ASSERT_EQ(g[0],c0*a0);
      ASSERT_EQ(g[1],a0*c1+a1*c0);
      ASSERT_EQ(g[2],a0*c2+a1*c1+a2*c0);
      ASSERT_EQ(g[3],a0*c3+a1*c2+a2*c1);
      ASSERT_EQ(g[4],a1*c3+a2*c2);
      ASSERT_EQ(g[5],a2*c3);

   }

int main(int argc,char **argv){
   ::testing::InitGoogleTest(&argc,argv);
   return RUN_ALL_TESTS();
}
