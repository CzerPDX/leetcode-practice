#include "solution.h"

std::string Solution::longestPalindrome(std::string s) {
  // Can assume that s will at least have a length of 1 based on the requirements
  std::string modifiedString = s;
  std::string longestSoFar = "";

  for (int i = 0; i <= modifiedString.length(); i += 2) {
    // |hello       0
    // |h|ello      2
    // |h|e|llo     4
    // |h|e|l|lo    6
    // |h|e|l|l|o   8
    // |h|e|l|l|o|  10
    modifiedString.insert(i, 1, '|');
  }

  // A flag for if I should stop looking early to avoid extra iterations
  bool stopLooking = false;
  std::string currSubstring;

  for (int i = 0; ((i < modifiedString.length()) && !stopLooking); i++) {
    currSubstring = "";

    // Start by adding the current letter of modifiedString to current substring
    currSubstring.insert(0, 1, modifiedString[i]);

    // Set up left and right indicies
    int left = i - 1;
    int right = i + 1;

    // Look on either side of the current i index to see if they match. If they do add them to the current substring and increment/decrement right and left
    while ((left >= 0) && (right < modifiedString.length()) && (modifiedString[left] == modifiedString[right])) {
      currSubstring.insert(0, 1, modifiedString[left]);
      currSubstring += modifiedString[right];
      left--;
      right++;
    }

    // If the current substring is longer than the longest so far, replace the longest so far.
    if (currSubstring.length() > longestSoFar.length()) {
      longestSoFar = currSubstring;
    }

    // If our last right index got to the end we can stop looking early.
    if (right == modifiedString.length()) {
      stopLooking = true;
    }
  }

  // Now remove all the |'s to clean up the return string
  std::string cleanedUpSubstring = "";
  for (int i = 0; i < longestSoFar.length(); i++) {
    if (longestSoFar[i] != '|') {
      cleanedUpSubstring += longestSoFar[i];
    }
  }

  return cleanedUpSubstring;
}