#include <bits/stdc++.h>
#include <set>
#include <algorithm>
#include <map>

#include "solution.h"

using namespace std;

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
  vector<vector<int>> retVectors;
  // set<vector<int>> uniqueVectors; // Using a set to collect vectors so there are no duplicates
  
  // Sort incoming nums array
  sort(nums.begin(), nums.end());

  // Going to try the 2 pointer approach:

  for (int i = 0; i < nums.size(); i++) {
    // Skip duplicates of the first number
    if ((i == 0) || (nums[i] != nums[i - 1])) {
      int left = i + 1;
      int right = nums.size() - 1;

      while (left < right) {
        // Want to look for a combination of left + right that adds up to -nums[i]
        // Move left to the right if it's too small.
        // Move right to the left if it's too large.
        // Save it if it's equal

        int sum = nums[left] + nums[right];
        if (sum == (nums[i] * -1)) {
          retVectors.push_back({ nums[i], nums[left], nums[right]});
          // uniqueVectors.insert({ nums[i], nums[left], nums[right] });

          // Advance left pointer and decrement right pointer till they aren't the same value they currently are
          while((left < right) && (nums[left] == nums[left + 1])) {
            left++;
          }
          while((left < right) && (nums[right] == nums[right - 1])) {
            right--;
          }

          // Then advance them once more
          left++;
          right--;
        } else if (sum < (nums[i] * -1)) {
          left++;
        } else {
          right--;
        }
      }
    }
  }

  // Assign retVectors to the unique vectors start end end
  // retVectors.assign(uniqueVectors.begin(), uniqueVectors.end());

  return retVectors;
}