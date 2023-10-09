#include "solution.h"
#include <iostream>
using namespace std;

/*
 From Leetcode:
 Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

 Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 
 Example 1:

 Input: x = 123
 Output: 321
 Example 2:

 Input: x = -123
 Output: -321
 Example 3:

 Input: x = 120
 Output: 21
  

 Constraints:

 -231 <= x <= 231 - 1
 */

int main(int argc, char *argv[]) {
  Solution *aSolution = new Solution();

  cout << aSolution->reverse(1234) << endl;
  
  cout << aSolution->reverse(-123) << endl;
  
  cout << aSolution->reverse(-2147483412) << endl;
  
  cout << aSolution->reverse(-2147483648) << endl;
  
  delete aSolution;

  return 0;
}
