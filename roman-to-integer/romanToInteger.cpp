#include "solution.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  Solution aSolution;

  cout << aSolution.romanToInt("III") << endl;

  cout << aSolution.romanToInt("LVIII") << endl;

  cout << aSolution.romanToInt("MCMXCIV") << endl;

  return 0;
}