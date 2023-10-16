/*
  From Leetcode:
  https://leetcode.com/problems/longest-palindromic-substring/

  Longest Palindromic Substring
  Given a string s, return the longest 
  palindromic substring in s.


  Example 1:

  Input: s = "babad"
  Output: "bab"
  Explanation: "aba" is also a valid answer.
  Example 2:

  Input: s = "cbbd"
  Output: "bb"
  

  Constraints:

  1 <= s.length <= 1000
  s consist of only digits and English letters.

*/

#include "solution.h"
#include <iostream>

int main(int argc, char *argv[]) {
  Solution aSolution;

  // std::cout << aSolution.longestPalindrome("babad") << std::endl;
  // std::cout << aSolution.longestPalindrome("cbbd") << std::endl;
  // std::cout << aSolution.longestPalindrome("aa") << std::endl;
  // std::cout << aSolution.longestPalindrome("aba") << std::endl;
  // std::cout << aSolution.longestPalindrome("ab") << std::endl;
  // std::cout << aSolution.longestPalindrome("aaaa") << std::endl;
  // std::cout << aSolution.longestPalindrome("ccc") << std::endl;
  std::cout << aSolution.longestPalindrome("abb") << std::endl;

  return 0;
}