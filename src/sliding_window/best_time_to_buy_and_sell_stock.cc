#include "deps.h"

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int min_price = INT_MAX;
        int max_profit = 0;

        // Iteration ensures the sequential check.
        for (auto price : prices)
        {
            min_price = min(min_price, price);
            max_profit = max(max_profit, price - min_price);
        }

        return max_profit;
    }
};
