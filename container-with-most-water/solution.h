#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int>& height);

private:
  int maxAreaInner(vector<int>& height);
};

#endif