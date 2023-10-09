#include <iostream>

#include "solution.h"

bool Solution::isMatch(string s, string p) {
  // There are a couple things I don't have to worry about (don't have to write edge cases for these)
    // There will always be an entry for both s and p
    // There will never be an invalid entry for p
    // Anything there is a * there will for sure be a preceeding valid character
    // s is only going to ever be lowercase english letters
    // p will only ever be lowercase english letters as well as . and *
  
  // Remaining cases are
    // I have reached the end of s but there is still p left
      // Return false
    // I have reached the end of p but there is still s left
      // Return false
    // I have reached the end of both s and p at the same time.
      // Return true
    // While I have not reached the end of either s or p
      // Look at the next set of rules for p and compare to the next characters for s to see if they match until a mismatch is hit
        // IF the character(s) matched before the mismatch
          // Begin loop again
        // ELSE IF there was no match before the first mismatch
          // Return false
  int sIdx = 0;
  int pIdx = 0;
  int sLen = s.length();
  int pLen = p.length();
  
  char characterPattern = p[pIdx];
  char modifier = p[pIdx];
  char nextPattern = p[pIdx];
  
  // While there is still both s and p left to look at compare the next set of rules with the next portion of s
  
  while ((sIdx < sLen) && (pIdx < pLen)) {
    // Get the next rule.
    // Cases:
      // A type of character: [a, z] or [97, 122]
        // Specific characters (lowercase letters)
        // Any character (.)
      // Followed by
        // A repeating modifier (*)
        // Nothing
    
    // Previous pattern could have been:
    // Nothing
    // A single character of some type
    // 0 - infinity character of any type
    // a - z
    if (nextPattern == '*') {
      // Look backward to find the character and advance sIdx until that character isn't found anymore
      char prevCharacter = p[pIdx - 1];
      if (prevCharacter != '.') {
        while ((s[sIdx] == prevCharacter) && (sIdx < sLen)) {
          sIdx++;
        }
      } else {
        // This is where I have to look to see what comes next because we have gotten '.*'
        // This can be 0 or more of any character. Need to account for situations like:
          // .*.*abc.*
            // This one means I can't just look ahead. But I guess for every .* in a row I can simply look to see if there are any actual characters or any . not followed by a * and then move sIdx to that character and move pIdx to whatever the first character is that isn't a . followed by a *
        // Advance to a non ".*" pair
        while ((p[pIdx] == '.') && (p[pIdx + 1] == '*') && ((pIdx + 1) < pLen)) {
          pIdx += 2;
        }
        // We are at something that isnt ".*" It could be:
          // Nothing (end of p so no more rules to look at)
          // A specific character
          // A "." that is not followed by a *
            // Could be followed by a character, ".", or the end of the string
        // If we are not at the end of the string (so there is something) at pIdx
        if (pIdx < pLen) {
          char nextCharacter = p[pIdx];
          if (nextCharacter != '.') {
            while ((s[sIdx] != nextCharacter) && (sIdx < sLen)) {
              sIdx++;
            }
          } else {
            // Otherwise we have a '.' We have to figure out what to do with sIdx.
            // If we have:
              // ..
              // .[specific character]
                // 
              // another .
              // end of the string
            // If ((pIdx + 1) == pLen) then this is the end of the string, compare p[pIdx] to s[sIdx] and see if they match and move on
          }
        } else {
          // Otherwise we are at the end of the string and it doesn't matter what else s has in it because it will match any valid characters remaining (even if there are none)
          return true;
        }
      }
    } else if (nextPattern == '.') {
      
    } else {
      
    }
    
  }
  
  // Check for edge cases of having s left with no p left or p left with no s left
  if ((sIdx < sLen) || (pIdx < pLen)) {
    return false;
  }
  
  return true;
}
