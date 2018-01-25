/*! @file Test_Polynomial.cpp 
 * @brief Contains the tests for the class Polynomial with field type as "double"
 */
#include "../include/Polynomial.ipp"
#include "gtest/gtest.h"
#include <stdexcept>
#include <utility>


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

   TEST_F(PolynomialTest,constructor_default) {
      Polynomial<double> f;
      ASSERT_EQ(f.size(),0);
   }
   TEST_F(PolynomialTest,constructor_init_list){
      double c0=1,c1=2,c2=3;
      Polynomial<double> f {c0,c1,c2};
      ASSERT_DOUBLE_EQ(f[0],c0);
      ASSERT_DOUBLE_EQ(f[1],c1);
      ASSERT_DOUBLE_EQ(f[2],c2);

   }
   TEST_F(PolynomialTest,appendTerm){
      double c0=1,c1=2,c2=3;
      Polynomial<double> f;
      f.appendTerm(c0);
      f.appendTerm(c1);
      f.appendTerm(c2);
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
   TEST_F(PolynomialTest,assignment_move){
      double c0=1,c1=2,c2=3;
      Polynomial<double> p {c0,c1,c2};
      Polynomial<double> f;
      f=std::move(p);
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

   TEST_F(PolynomialTest,sum_assign_operator){
      double c0=1,c1=2,c2=3,c3=0;
      double a0=4,a1=0,a2=6,a3=10;
      Polynomial<double> fc {c0,c1,c2,c3};
      Polynomial<double> fa {a0,a1,a2,a3};
      
      fc+=fa;
      ASSERT_EQ(fc.size(),4);
      ASSERT_EQ(fa.size(),4);
      
      ASSERT_DOUBLE_EQ(fc[0],c0+a0);
      ASSERT_DOUBLE_EQ(fc[1],c1+a1);
      ASSERT_DOUBLE_EQ(fc[2],c2+a2);
      ASSERT_DOUBLE_EQ(fc[3],c3+a3);
      ASSERT_DOUBLE_EQ(fa[0],a0);
      ASSERT_DOUBLE_EQ(fa[1],a1);
      ASSERT_DOUBLE_EQ(fa[2],a2);
      ASSERT_DOUBLE_EQ(fa[3],a3);


   }
   TEST_F(PolynomialTest,sum_assign_operator_rvalue_ref){
      double c0=1,c1=2,c2=3,c3=0;
      double a0=4,a1=0,a2=6,a3=10;
      Polynomial<double> fc {c0,c1,c2,c3};
      
      fc+=(Polynomial<double> {a0,a1,a2,a3});
      ASSERT_EQ(fc.size(),4);
      
      ASSERT_DOUBLE_EQ(fc[0],c0+a0);
      ASSERT_DOUBLE_EQ(fc[1],c1+a1);
      ASSERT_DOUBLE_EQ(fc[2],c2+a2);
      ASSERT_DOUBLE_EQ(fc[3],c3+a3);

   }
   TEST_F(PolynomialTest,subtract_assign_operator){
      double c0=1,c1=2,c2=3,c3=0;
      double a0=4,a1=0,a2=6,a3=10;
      Polynomial<double> fc {c0,c1,c2,c3};
      Polynomial<double> fa {a0,a1,a2,a3};
      
      fc-=fa;
      ASSERT_EQ(fc.size(),4);
      ASSERT_EQ(fa.size(),4);
      
      ASSERT_DOUBLE_EQ(fc[0],c0-a0);
      ASSERT_DOUBLE_EQ(fc[1],c1-a1);
      ASSERT_DOUBLE_EQ(fc[2],c2-a2);
      ASSERT_DOUBLE_EQ(fc[3],c3-a3);
      ASSERT_DOUBLE_EQ(fa[0],a0);
      ASSERT_DOUBLE_EQ(fa[1],a1);
      ASSERT_DOUBLE_EQ(fa[2],a2);
      ASSERT_DOUBLE_EQ(fa[3],a3);


   }
   TEST_F(PolynomialTest,subtract_assign_operator_rvalue_ref){
      double c0=1,c1=2,c2=3,c3=0;
      double a0=4,a1=0,a2=6,a3=10;
      Polynomial<double> fc {c0,c1,c2,c3};
      
      fc-=(Polynomial<double> {a0,a1,a2,a3});
      ASSERT_EQ(fc.size(),4);
      
      ASSERT_DOUBLE_EQ(fc[0],c0-a0);
      ASSERT_DOUBLE_EQ(fc[1],c1-a1);
      ASSERT_DOUBLE_EQ(fc[2],c2-a2);
      ASSERT_DOUBLE_EQ(fc[3],c3-a3);

   }
   TEST_F(PolynomialTest,unary_minus_operator_rvalue){
      double a0=4,a1=0,a2=6,a3=10;
      Polynomial<double> fa =-(Polynomial<double> {a0,a1,a2,a3});
      
      ASSERT_DOUBLE_EQ(fa[0],-a0);
      ASSERT_DOUBLE_EQ(fa[1],-a1);
      ASSERT_DOUBLE_EQ(fa[2],-a2);
      ASSERT_DOUBLE_EQ(fa[3],-a3);
   }
   TEST_F(PolynomialTest,unary_minus_operator){
      double a0=4,a1=0,a2=6,a3=10;
      Polynomial<double> fa {a0,a1,a2,a3};
      Polynomial<double> f =-fa;
      
      ASSERT_DOUBLE_EQ(f[0],-a0);
      ASSERT_DOUBLE_EQ(f[1],-a1);
      ASSERT_DOUBLE_EQ(f[2],-a2);
      ASSERT_DOUBLE_EQ(f[3],-a3);
   }
   TEST_F(PolynomialTest,helper_minus){
      double a0=4,a1=0,a2=6,a3=10;
      Polynomial<double> fa {a0,a1,a2,a3};
      fa.minus();
      ASSERT_EQ(fa.size(),4);
      
      ASSERT_DOUBLE_EQ(fa[0],-a0);
      ASSERT_DOUBLE_EQ(fa[1],-a1);
      ASSERT_DOUBLE_EQ(fa[2],-a2);
      ASSERT_DOUBLE_EQ(fa[3],-a3);


   }
   TEST_F(PolynomialTest,add_operator){
      double c0=1,c1=2,c2=3,c3=0;
      double a0=4,a1=0,a2=6,a3=10;
      Polynomial<double> fc {c0,c1,c2,c3};
      Polynomial<double> fa {a0,a1,a2,a3};
      
      Polynomial<double> f=fa+fc;
      ASSERT_EQ(fc.size(),3);
      ASSERT_EQ(fa.size(),4);
      ASSERT_EQ(f.size(),4);

      
      ASSERT_DOUBLE_EQ(f[0],c0+a0);
      ASSERT_DOUBLE_EQ(f[1],c1+a1);
      ASSERT_DOUBLE_EQ(f[2],c2+a2);
      ASSERT_DOUBLE_EQ(f[3],c3+a3);
      ASSERT_DOUBLE_EQ(fa[0],a0);
      ASSERT_DOUBLE_EQ(fa[1],a1);
      ASSERT_DOUBLE_EQ(fa[2],a2);
      ASSERT_DOUBLE_EQ(fa[3],a3);
      ASSERT_DOUBLE_EQ(fc[0],c0);
      ASSERT_DOUBLE_EQ(fc[1],c1);
      ASSERT_DOUBLE_EQ(fc[2],c2);

   }
   TEST_F(PolynomialTest,add_operator_rvalue){
      double c0=1,c1=2,c2=3,c3=0;
      double a0=4,a1=0,a2=6,a3=10;
      
      Polynomial<double> fa {a0,a1,a2,a3};
      
      Polynomial<double> f=fa+(Polynomial<double> {c0,c1,c2,c3});
      ASSERT_EQ(fa.size(),4);
      ASSERT_EQ(f.size(),4);

      
      ASSERT_DOUBLE_EQ(f[0],c0+a0);
      ASSERT_DOUBLE_EQ(f[1],c1+a1);
      ASSERT_DOUBLE_EQ(f[2],c2+a2);
      ASSERT_DOUBLE_EQ(f[3],c3+a3);
      ASSERT_DOUBLE_EQ(fa[0],a0);
      ASSERT_DOUBLE_EQ(fa[1],a1);
      ASSERT_DOUBLE_EQ(fa[2],a2);
      ASSERT_DOUBLE_EQ(fa[3],a3);

   }
   TEST_F(PolynomialTest,subtract_operator){
      double c0=1,c1=2,c2=3,c3=10;
      double a0=4,a1=0,a2=6,a3=10;
      Polynomial<double> fc {c0,c1,c2,c3};
      Polynomial<double> fa {a0,a1,a2,a3};
      
      Polynomial<double> f=fa-fc;
      ASSERT_EQ(fc.size(),4);
      ASSERT_EQ(fa.size(),4);
      ASSERT_EQ(f.size(),3);

      
      ASSERT_DOUBLE_EQ(f[0],a0-c0);
      ASSERT_DOUBLE_EQ(f[1],a1-c1);
      ASSERT_DOUBLE_EQ(f[2],a2-c2);
      ASSERT_DOUBLE_EQ(fa[0],a0);
      ASSERT_DOUBLE_EQ(fa[1],a1);
      ASSERT_DOUBLE_EQ(fa[2],a2);
      ASSERT_DOUBLE_EQ(fa[3],a3);
      ASSERT_DOUBLE_EQ(fc[0],c0);
      ASSERT_DOUBLE_EQ(fc[1],c1);
      ASSERT_DOUBLE_EQ(fc[2],c2);

   }


   TEST_F(PolynomialTest,multiply_operator){
      double c0=1,c1=2,c2=3,c3=4;
      double a0=4,a1=0,a2=6;
      Polynomial<double> fc {c0,c1,c2,c3};
      Polynomial<double> fa {a0,a1,a2};
      
      Polynomial<double> f=fa*fc;
      ASSERT_EQ(f.size(),6);

      
      ASSERT_DOUBLE_EQ(f[0],c0*a0);
      ASSERT_DOUBLE_EQ(f[1],a0*c1+a1*c0);
      ASSERT_DOUBLE_EQ(f[2],a0*c2+a1*c1+a2*c0);
      ASSERT_DOUBLE_EQ(f[3],a0*c3+a1*c2+a2*c1);
      ASSERT_DOUBLE_EQ(f[4],a1*c3+a2*c2);
      ASSERT_DOUBLE_EQ(f[5],a2*c3);

      Polynomial<double> g=fa*fc;
      ASSERT_EQ(g.size(),6);

      
      ASSERT_DOUBLE_EQ(g[0],c0*a0);
      ASSERT_DOUBLE_EQ(g[1],a0*c1+a1*c0);
      ASSERT_DOUBLE_EQ(g[2],a0*c2+a1*c1+a2*c0);
      ASSERT_DOUBLE_EQ(g[3],a0*c3+a1*c2+a2*c1);
      ASSERT_DOUBLE_EQ(g[4],a1*c3+a2*c2);
      ASSERT_DOUBLE_EQ(g[5],a2*c3);

   }

int main(int argc,char **argv){
   ::testing::InitGoogleTest(&argc,argv);
   return RUN_ALL_TESTS();
}
