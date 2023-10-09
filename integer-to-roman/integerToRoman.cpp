/*
From Leetcode:
https://leetcode.com/problems/integer-to-roman/ 

Integer to Roman
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999
*/

#include <iostream>
#include <string>

#include "solution.h"
using namespace std;


int main(int argc, char *argv[]) {

  Solution *aSolution = new Solution();

  cout << aSolution->intToRoman(1) << endl;
  cout << aSolution->intToRoman(2) << endl;
  cout << aSolution->intToRoman(3) << endl;
  cout << aSolution->intToRoman(4) << endl;
  cout << aSolution->intToRoman(5) << endl;
  cout << aSolution->intToRoman(6) << endl;
  cout << aSolution->intToRoman(7) << endl;
  cout << aSolution->intToRoman(8) << endl;
  cout << aSolution->intToRoman(9) << endl;
  cout << aSolution->intToRoman(10) << endl;

  cout << aSolution->intToRoman(11) << endl;
  cout << aSolution->intToRoman(12) << endl;
  cout << aSolution->intToRoman(13) << endl;
  cout << aSolution->intToRoman(14) << endl;
  cout << aSolution->intToRoman(15) << endl;
  cout << aSolution->intToRoman(16) << endl;
  cout << aSolution->intToRoman(17) << endl;
  cout << aSolution->intToRoman(18) << endl;
  cout << aSolution->intToRoman(19) << endl;
  cout << aSolution->intToRoman(20) << endl;

  cout << aSolution->intToRoman(61) << endl;

  cout << aSolution->intToRoman(1994) << endl;

  delete aSolution;
  return 0;
}