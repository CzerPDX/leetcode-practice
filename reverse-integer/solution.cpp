#ifndef SOLUTION_CPP
#define SOLUTION_CPP

#include <iostream>
#include "solution.h"
using namespace std;


int Solution::reverse(int x) {
  int retVal = 0;
    
  while (x != 0) {
    // First grab the digit off the end of x
    int endDigit = x % 10;
    
    // Then check for overflow/underflow
    // It will overflow next time if
      // The retVal is greater than 214748364
      // OR retVal is equal to 214748364 AND the endDigit is greater than 7
    // It will underflow next time if
      // The retVal is less than -214748364
      // OR retVal is equal to -214748364 AND the endDigit is greater than 8
    if (retVal > 214748364 || (retVal == 214748364 && endDigit > 7)) {
      return 0;
    }
    if (retVal < -214748364 || (retVal == -214748364 && endDigit < -8)) {
      return 0;
    }
    
    // Multiply retVal by 10 to give space for the endDigit, then add the endDigit onto retVal
    retVal = (retVal * 10) + endDigit;
    // Remove endDigit from the end of x
    x /= 10;
  }
  
  return retVal;
}


#endif
