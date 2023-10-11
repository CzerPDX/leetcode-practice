#include <bits/stdc++.h>
#include <set>
#include <algorithm>

#include "solution.h"

using namespace std;

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
  vector<vector<int>> retVectors;

  // Sort nums to make it easier to find values
  sort(nums.begin(), nums.end()); 

  // Slow version first
  for (vector<int>::iterator first = nums.begin(); first != nums.end(); first++) {
    for (vector<int>::iterator second = first + 1; second != nums.end(); second++) {
      int secondSum = *first + *second;
      bool thirdFound = false;
      for (vector<int>::iterator third = second + 1; ((third != nums.end()) && (!thirdFound)); third++) {
        if ((secondSum + *third) == 0) {
          thirdFound = true;
          vector<int> vectorToAdd = {*first, *second, *third};
          retVectors.push_back(vectorToAdd);
        }
      }
    }
  }

  // Get rid of duplidates
  set<vector<int>> uniqueVectors(retVectors.begin(), retVectors.end());
  retVectors.assign(uniqueVectors.begin(), uniqueVectors.end());

  return retVectors;
}