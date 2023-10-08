#include "solution.h"
#include <iostream>

int Solution::myAtoi(string s) {
  // General info:
  // ASCII chars ['0', '99] are mapped to the digits [48, 57]
  
  int   retVal = 0;
  int   currIdx = 0;
  int   sLen = s.length();
  int   finalMultiplier = 1;
  
  // Start checking.
  // First characters may be leading whitespace
  while ((s[currIdx] == ' ') && (currIdx < sLen)) {
    currIdx++;
  }
  
  // Next character can be either +, -, or neither.
  if (s[currIdx] == '+') {
    currIdx++;
  } else if (s[currIdx] == '-') {
    finalMultiplier = -1;
    currIdx++;
  }
  
  // Then check for leading 0's and ignore them
  while (s[currIdx] == '0') {
    currIdx++;
  }
  
  // Only digits can be read after that.
  // Once you either hit the end of the string or read a non-digit after finding a single digit, stop checking.
  // Count numerals successfully added
  while ((s[currIdx] >= '0') && (s[currIdx] <= '9') && (currIdx < sLen)) {
    int nextValue = s[currIdx] - 48;
    
    // IF there is no way to add a next digit without overflowing
    // (retVal > 214748364)
      // IF finalMultiplier is negative, return -2147483648
      // ELSE IF finalMultiplier is positive, return 2147483647
    // ELSE IF there is a question as to whether the next digit will make it overflow
    // (retVal == 214748364)
      // IF the number is negative and the next digit is greater than or equal to 8 it
      // will overflow
        // Return -2147483648
      // ELSE IF the number is positive and the next digit is greater than or equal to 7
        // Return 2147483647
    // Otherwise, the next digit cannot possibly make it overflow so we can continue.
    
    if (retVal > 214748364) {
      if (finalMultiplier == 1) {
        return 2147483647;
      } else if (finalMultiplier == -1) {
        return -2147483648;
      }
    } else if (retVal == 214748364) {
      if ((s[currIdx] >= '7') && (finalMultiplier == 1)) {
        return 2147483647;
      } else if ((s[currIdx] >= '8') && (finalMultiplier == -1)) {
        return -2147483648;
      }
    }
    
    // Add the next number to retVal and increment currIdx
    retVal = (retVal * 10) + (s[currIdx] - '0');
    currIdx++;
  }
  
  // Add the sign
  retVal *= finalMultiplier;
  return retVal;
}
