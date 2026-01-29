#include "deps.h"

class Solution {
 public:
  int maxArea(vector<int>& heights) {
    int left = 0, right = heights.size() - 1;
    int maxWater = 0;

    while (left < right) {
      int h = min(heights[left], heights[right]);
      int width = right - left;
      maxWater = max(maxWater, h * width);

      if (heights[left] < heights[right])
        ++left;
      else
        --right;
    }

    return maxWater;
  }
};
