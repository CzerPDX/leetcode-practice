#include "solution.h"

#include <iostream>


void printVectorOfIntVectors(std::vector<std::vector<int>> vecOfIntVectorsToPrint) {
  for (int i = 0; i < vecOfIntVectorsToPrint.size(); i++) {
    std::cout << "< ";
    for (int j = 0; j < vecOfIntVectorsToPrint[i].size(); j++) {
      std::cout << vecOfIntVectorsToPrint[i][j] << " ";
    }
    std::cout << "> " << std::endl;
  }
}

int main(int argc, char *argv[]) {

  Solution aSolution;

  std::vector<int> testVec = {1,0,-1,0,-2,2};
  printVectorOfIntVectors(aSolution.fourSum(testVec, 0));

  std::vector<int> testVec2 = {2,2,2,2,2};
  printVectorOfIntVectors(aSolution.fourSum(testVec2, 8));

  std::vector<int> testVec3 = {1000000000,1000000000,1000000000,1000000000};
  printVectorOfIntVectors(aSolution.fourSum(testVec3, 0));


  return 0;
}