#include "solution.h"

#include <iostream>
#include <algorithm>

int Solution::threeSumClosest(std::vector<int>& nums, int target) {
  // Sort nums
  sort(nums.begin(), nums.end());

  // Set closesetSoFar to an invalid target value that is so far away from possible maximum target value that it will never be closest.
  // Min is -10^4 = -10000.  Max is 10^4 = 10000
  // If target is -10000 and the closest value to it is an array of the farthest possible away values then I have
  //  then the largest possible value away is: abs(10000 + 10000 + 10000) = 30000
  // If the number is at a maximum end of the spectrum then I need to add that plus one to make sure I am always outside 
  // the bounds for closestSoFar's default value: abs(nums max) + abs(target min - target max) = 1000 + 30000 = 31000
  // Then add one so it's always just beyond that value 31001
  int closestSoFar = 31001;

  for (int i = 0; i < nums.size(); i++) {
    // Skip duplicates for the first number (nums[i])
    if ((i == 0) || (nums[i] != nums[i - 1])) {
      int left = i + 1; 
      int right = nums.size() - 1;

      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];

        // Find out the absolute value of target - sum. if it is closer than the absolute value of closest so far, save it as the new closest so far
        int currentAmtAway = abs(sum - target);
        int closestSoFarAmtAway = abs(closestSoFar - target);
        if (abs(target - sum) < abs(target - closestSoFar)) {
          closestSoFar = sum;
        }

        if (sum == target) {
          // Return closestSoFar
          return closestSoFar;
        } else if (sum < target) {
          // [2, 2, 2, 3, 4, 5]
          // Increase left until it's no longer the same as the current left value to avoid duplicates
          while ((left < right) && (nums[left] == nums[left + 1])) {
            left++;
          }
          left++;
        } else {
          // Decrease right until it's no longer the same as the current right value to avoid duplicates
          while ((left < right) && (nums[right] == nums[right - 1])) {
            right--;
          }
          right--;
        }
      }
    }
    
  }

  return closestSoFar;
}