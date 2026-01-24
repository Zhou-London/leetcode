#include "deps.h"
using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        using num = int;
        using index = int;

        unordered_map<num, index> map;

        for (int i = 0; i < nums.size(); ++i)
        {
            int complement = target - nums[i];

            auto it = map.find(complement);
            if (it != map.end())
                return {it->second, i};

            map[nums[i]] = i;
        }

        return {};
    }
};
