
#include "solution.h"

std::vector<std::string> Solution::fizzBuzz(int n) {
  std::vector<std::string> retStrings;

  for (int i = 1; i <= n; i++) {
    std::string stringToAdd = "";

    if ((i % 3) == 0) {
      stringToAdd += "Fizz";
    }

    if ((i % 5) == 0) {
      stringToAdd += "Buzz";
    }

    if (stringToAdd == "") {
      stringToAdd = std::to_string(i);
    }

    retStrings.push_back(stringToAdd);
  }

  return retStrings;
}