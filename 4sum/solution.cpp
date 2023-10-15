#include "solution.h"

#include <iostream>
#include <bits/stdc++.h>

std::vector<std::vector<int>> Solution::fourSum(std::vector<int>& nums, int target) {
  int numsSize = nums.size();
  std::vector<std::vector<int>> retVector;

  // This allows num vectors of less than 4. We can't use those so only proceed if there are 4 or more entries in nums
  if (numsSize >= 4) {
    // Sort the array
    sort(nums.begin(), nums.end());

    // For each entry in nums (stop when first will be fourth from last)
    for (int first = 0; first < numsSize - 3; first++) {
      // This allows me to skip duplicates of first, but the 0th entry needs to be allowed
      if ((first == 0) || (nums[first] != nums[first - 1])) {
        int second = first + 1;
        int third = second + 1;
        int fourth = numsSize - 1;

        // While third is less than fourth (includes reset of third and fourth based on 2nd at the bottom)
        while (third < fourth) {
          // While third is less than fourth (pre-reset)
          while (third < fourth) {
            // Cast sum and all operands to long because the num limits allow for numbers that can be summed to more than max int
            long sum = (long)nums[first] + (long)nums[second] + (long)nums[third] + (long)nums[fourth];
            if (sum < target) {
              // increment third until third is not at a duplicate
              while ((third < fourth) && (nums[third] == nums[third + 1])) {
                third++;
              }
              third++;
            } else if (sum > target) {
              // decrement fourth until fourth is not at a duplicate
              while ((third < fourth) && (nums[fourth] == nums[third - 1])) {
                fourth--;
              }
              fourth--;
            } else {
              // save the match and either increment third or decrement fourth to a non-duplicate
              retVector.push_back({nums[first], nums[second], nums[third], nums[fourth]});

              // Increment third till not a duplicate
              while ((third < fourth) && (nums[third] == nums[third + 1])) {
                third++;
              }
              third++;
            }
          }

          // Increment second till not a duplicate
          while ((second < (numsSize - 2)) && (nums[second] == nums[second + 1])) {
            second++;
          }
          second++;

          // Reset third and fourth
          third = second + 1;
          fourth = numsSize - 1;
        }
      }
    }
  }
  
  return retVector;
}