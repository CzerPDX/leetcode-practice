/*
  From Leetcode:
  14. Longest Common Prefix
  https://leetcode.com/problems/longest-common-prefix/

  Write a function to find the longest common prefix string amongst an array of strings.

  If there is no common prefix, return an empty string "".

  

  Example 1:

  Input: strs = ["flower","flow","flight"]
  Output: "fl"
  Example 2:

  Input: strs = ["dog","racecar","car"]
  Output: ""
  Explanation: There is no common prefix among the input strings.
  

  Constraints:

  1 <= strs.length <= 200
  0 <= strs[i].length <= 200
  strs[i] consists of only lowercase English letters.
*/
#include <iostream>
#include <string>
#include <vector>

#include "solution.h"

using namespace std;

int main(int argc, char *argv[]) {

  Solution aSolution;

  vector<string> strs{ "flower", "flow", "flight" };
  cout << aSolution.longestCommonPrefix(strs) << endl;

  vector<string> strs2{ "dog", "racecar", "car" };
  cout << aSolution.longestCommonPrefix(strs2) << endl;

  return 0;
}