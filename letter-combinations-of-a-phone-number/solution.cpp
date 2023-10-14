#include "solution.h"

#include <iostream>
#include <cstring>


std::vector<std::string> Solution::letterCombinations(std::string digits) {
  std::vector<std::string> retVector;

  // Create array of char arrays:
  std::string letterMap[8] = {
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
  };

  // For every digit in the digits string
  for (int i = (digits.length() - 1); i >= 0; i--) {
    int letterMapIdx = (int)digits[i] - 48 - 2;
    // Start a new array if retVector is empty
    if (retVector.size() == 0) {
      // For each letter at the current digit's letterMap string, add it to the retVector as its own string
      for (int j = 0; j < letterMap[letterMapIdx].length(); j++) {
        retVector.push_back(std::string(1, letterMap[letterMapIdx][j]));
      }
    } else {
      // If retVector is not empty build a new retVector
      std::vector<std::string> newRetVector;
      // For each item in retVector, add a new letter to it from the current letterMap string
      for (int j = 0; j < retVector.size(); j++) {
        for (int k = 0; k < letterMap[letterMapIdx].length(); k++) {
          newRetVector.push_back(letterMap[letterMapIdx][k] + retVector[j]);
        }
      }
      // Replace retVector with a newRetVector
      retVector = newRetVector;
    }
  }

  return retVector;
}