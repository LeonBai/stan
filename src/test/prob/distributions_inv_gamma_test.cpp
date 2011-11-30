// These tests should not have reference to stan::agrad::var. Distribution tests 
// with stan::agrad::var should be placed in src/test/agrad/distributions_test.cpp

#include <cmath>
#include <gtest/gtest.h>
#include "stan/prob/distributions_inv_gamma.hpp"

TEST(distributions,InvGamma) {
  EXPECT_FLOAT_EQ(-1, stan::prob::inv_gamma_log(1,1,1.0));
  EXPECT_FLOAT_EQ(-0.8185295, stan::prob::inv_gamma_log(0.5,2.9,3.1));
}
TEST(distributions,InvGammaDefaultPolicy) {
  double y = 0.5;
  double alpha = 1.0;
  double beta = 2.0;
  
  EXPECT_NO_THROW(stan::prob::inv_gamma_log(y, alpha, beta));
  EXPECT_THROW (stan::prob::inv_gamma_log(0.0, alpha, beta), std::domain_error);
  EXPECT_THROW (stan::prob::inv_gamma_log(-1, alpha, beta), std::domain_error);
  EXPECT_THROW (stan::prob::inv_gamma_log(y, 0.0, beta), std::domain_error);
  EXPECT_THROW (stan::prob::inv_gamma_log(y, -1.0, beta), std::domain_error);
  EXPECT_THROW (stan::prob::inv_gamma_log(y, alpha, 0.0), std::domain_error);
  EXPECT_THROW (stan::prob::inv_gamma_log(y, alpha, -1.0), std::domain_error);
}
