/* Koko eating bananas */
// * Medium

#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool canEatAll(vector<int> &piles, int k, int h)
    {
        long long hours = 0;
        for (int bananas : piles)
            hours += (bananas + k - 1) / k;

        return hours <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (canEatAll(piles, mid, h))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};