#include "solution.h"
#include <iostream>
using namespace std;

Solution::Solution() {
  cout << "constructor running" << endl;
}

Solution::~Solution() {
  cout << "destrutor running" << endl;
}

string Solution::intToRoman(int num) {
  string retStr = "";

  char symbols[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
  
  int symbolsIdx = 0;
  int currDigit = 0;
  int modResult = 0;


  while ((num > 0) && (symbolsIdx < (sizeof(symbols) - 1))) {
    currDigit = num % 10;
    modResult = currDigit % 5;
    
    // Using a switch statement here to try to save some computation time since I can't figure out the mathematical "trick" to make this super fast
    // Insert the correct values onto the front of the string
    switch(currDigit) {
      case 0:
        break;
      case 1:
      case 2:
      case 3:
        retStr.insert(0, modResult, symbols[symbolsIdx]);
        break;
      case 4:
        retStr.insert(0, {symbols[symbolsIdx], symbols[symbolsIdx + 1]});
        break;
      case 5:
        retStr.insert(0, 1, symbols[symbolsIdx + 1]);
        break;
      case 6:
      case 7:
      case 8:
        retStr.insert(0, modResult, symbols[symbolsIdx]);
        retStr.insert(0, 1, symbols[symbolsIdx + 1]);
        break;
      case 9:
        retStr.insert(0, {symbols[symbolsIdx], symbols[symbolsIdx + 2]});
    }

    symbolsIdx += 2;
    num /= 10;
  }

  // Take care of anything over 1000
  retStr.insert(0, num, 'M');

  return retStr;
}