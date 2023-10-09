#include <iostream>
#include "solution.h"


int Solution::maxArea(vector<int> &height) {
  return Solution::maxAreaInner(height);
}

int Solution::maxAreaInner(vector<int> &height) {
  int largestSoFar = 0;
  int left = 0;
  int right = height.size() - 1;

  while (left < right) {
    largestSoFar = max(largestSoFar, min(height[left], height[right]) * (right - left));

    // Move the index with the lowest height toward the center
    if (height[left] < height[right]) {
      left++;
    } else {
      right--;
    }
  }

  return largestSoFar;
}