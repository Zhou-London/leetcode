/* 3Sum */
// * Medium

#include <vector>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        const int n = (int)nums.size();
        if (n < 3)
            return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i)
        {
            int a = nums[i];

            if (a > 0)
                break;

            if (i > 0 && a == nums[i - 1])
                continue;

            long long minSum = (long long)a + nums[i + 1] + nums[i + 2];
            if (minSum > 0)
                break;

            long long maxSum = (long long)a + nums[n - 1] + nums[n - 2];
            if (maxSum < 0)
                continue;

            int l = i + 1, r = n - 1;
            while (l < r)
            {
                long long s = (long long)a + nums[l] + nums[r];
                if (s == 0)
                {
                    res.push_back({a, nums[l], nums[r]});

                    int lv = nums[l], rv = nums[r];
                    while (l < r && nums[l] == lv)
                        ++l;
                    while (l < r && nums[r] == rv)
                        --r;
                }
                else if (s < 0)
                {
                    ++l;
                }
                else
                {
                    --r;
                }
            }
        }

        return res;
    }
};