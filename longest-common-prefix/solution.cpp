#include "solution.h"

using namespace std;

string Solution::longestCommonPrefix(vector<string> &strs) {
  // Every item on the list is going to have to have a common prefix or "" is returned.
  // I don't need to do anything fancy here. Sorting is not required or helpful.
  // I just need to look at every item on the list one index at a time and compare it to the current char. 
  // As soon as I find one that doesn't match stop looking and don't add that one to the retPrefix.
  
  string retPrefix = "";
  int currIdx = 0;
  bool stopLooking = false;
  char currChar = ' ';
  
  while (!stopLooking) {
    if (currIdx < strs[0].length()) {
      currChar = strs[0][currIdx];
    } else {
      stopLooking = true;
    }
    for (int i = 0; ((i < strs.size()) && (!stopLooking)); i++) {
      if (strs[i].length() > currIdx) {
        if (strs[i][currIdx] != currChar) {
          stopLooking = true;
        }
      } else {
        stopLooking = true;
      }
    }
    if (!stopLooking) {
      retPrefix += currChar;
      currIdx++;
    }
  }

  return retPrefix;
}