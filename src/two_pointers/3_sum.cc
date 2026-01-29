#include "deps.h"

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    using ReturnType = vector<vector<int>>;
    using FixedNumber = size_t;

    ReturnType result;
    size_t n = nums.size();
    if (n < 3) return result;

    sort(nums.begin(), nums.end());

    for (FixedNumber i = 0; i < n - 2; ++i) {
      if (nums[i] > 0) break;
      if (i > 0 && nums[i] == nums[i - 1]) continue;

      int left = i + 1, right = n - 1;
      int target = -nums[i];

      while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) {
          result.push_back({nums[i], nums[left], nums[right]});

          while (nums[left] == nums[left + 1] && left < right) ++left;
          while (nums[right] == nums[right - 1] && left < right) --right;
          ++left;
          --right;
        } else if (sum < target)
          ++left;
        else if (sum > target)
          --right;
      }
    }
    return result;
  }
};
