#ifndef __STAN__MATH__FUNCTIONS__FALLING_FACTORIAL_HPP__
#define __STAN__MATH__FUNCTIONS__FALLING_FACTORIAL_HPP__

#include <boost/math/special_functions/gamma.hpp>

namespace stan {
  namespace math {

    template<typename T>
    inline T
    falling_factorial(const T x, const int n) { 
      using boost::math::tgamma;
      return tgamma(x + 1) / tgamma(n + 1); 
    }

  }
}

#endif
