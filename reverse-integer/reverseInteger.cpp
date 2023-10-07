#include "solution.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  Solution *aSolution = new Solution();

  cout << aSolution->reverse(1234) << endl;

  delete aSolution;

  return 0;
}
