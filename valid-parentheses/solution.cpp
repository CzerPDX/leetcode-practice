


#include "solution.h"

bool Solution::isValid(std::string s) {
  // ( = 40
  // ) = 41

  // [ = 91
  // ] = 93

  // { = 123
  // } = 125

  // Valid strings will have an even number of digits
  // An odd numbered length indicates a mismatch without needing to look
  if (s.length() % 2 != 0) {
    return false;
  }

  // Build a mirror string that will act like a stack of characters
  // It will be filled with opening characters and will pop off closing characters
  std::string mirrorString = "";

  while (s.length() > 0) {
    char nextChar = s[0];
    // So there are two types of characters s[0] could be:
    // An opening character (, [, { with char values of 40, 91, or 123
    // Or a closing character ), ] }

    // If s[0] is an opening character
    if ((nextChar == 40) || (nextChar == 91) || (nextChar == 123)) {
      // Add it to the front of the mirrorString and then delete that character from the front of s
      mirrorString.insert(0, 1, nextChar);
      s.erase(0, 1);
    }
    
    // Otherwise we've come across a closing character
    else {
      // If there's no matching opening character in the mirroString stack then I know this is a bad pattern and can return false
      if (mirrorString.length() == 0) {
        return false;
      }

      // Now check that the character at the top of mirrorString is the correct one.
      // If it doesn't match the one it should be, return false.
      // If it does match the one it should be, pop it off of s and pop its opening character off of the mirrorString stack
      switch(mirrorString[0]) {
        case '(':
          if (nextChar != ')') {
            return false;
          } else {
            s.erase(0, 1);
            mirrorString.erase(0, 1);
          }
          break;
        case '[':
          if (nextChar != ']') {
            return false;
          } else {
            s.erase(0, 1);
            mirrorString.erase(0, 1);
          }
          break;
        case '{':
          if (nextChar != '}') {
            return false;
          } else {
            s.erase(0, 1);
            mirrorString.erase(0, 1);
          }
          break;
      }
    }
  }

  // If there are still characters left in mirrorString or in the original s string I know it's a bad pattern so return false
  if ((mirrorString.length() != 0) || (s.length() != 0)) {
    return false;
  }

  return true;
}