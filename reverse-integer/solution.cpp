#ifndef SOLUTION_CPP
#define SOLUTION_CPP

#include <iostream>
#include "solution.h"
using namespace std;


int Solution::reverse(int x) {
  int retVal = 0;
  int modNum = 10;

  if ((x <= -8463847412) || (x >= 7463847412)) {
    return 0;
  }

  while (x > 0) {
    retVal = retVal + (x % 10);
    x /= 10;
    retVal *= 10;
  }

  retVal /= 10;

  return retVal;
}


#endif