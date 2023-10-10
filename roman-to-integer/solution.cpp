#include "solution.h"

#include <map>
#include <iostream>
using namespace std;

int Solution::romanToInt(string s) {
  map<char, int> values = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
  };

  int retInt = 0;

  // I, X, or C can have negative values in these situations:
  // If I comes before X or V
  // If X comes before L or C
  // If C comes before D or M
  // In these situations the common denominator is that the value 
  // that comes next is higher than the one before 
  // (ie IX is a lower value 'I' followed by a higher value 'X')
  // So I should be able to check ahead to see if the value ahead is greater and if so the current value is added as a negative.
  // This I think gives me O(2N)

  for (int i = 0; i < (s.length() - 1); i++) {
    if (values[s[i]] >= values[s[i + 1]]) {
      retInt += values[s[i]];
    } else {
      retInt -= values[s[i]];
    }
  }

  // Stopped one before the end to avoid dereference, so need to handle the last remaining one
  
  retInt += values[s[s.length() - 1]];

  return retInt;
}