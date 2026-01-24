#include "deps.h"

// * Heap
class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        using Number = int;
        using Frequency = int;
        using Pair = pair<Frequency, Number>;
        using ReturnType = vector<int>;

        unordered_map<Number, Frequency> freq;
        for (int n : nums)
            ++freq[n];

        auto cmp = [](Pair &a, Pair &b) { return a.first > b.first; };

        using PQType = priority_queue<Pair, vector<Pair>, decltype(cmp)>;
        PQType pq(cmp);

        for (auto &[num, count] : freq)
        {
            pq.push({count, num});
            if (pq.size() > k)
                pq.pop();
        }

        ReturnType result;
        result.reserve(k);
        while (!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
// * Bucket
class Solution2
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        using Number = int;
        using Frequency = int;
        using ReturnType = vector<Number>;

        unordered_map<Number, Frequency> freq;
        for (int n : nums)
            ++freq[n];

        vector<vector<Number>> buckets(nums.size() + 1);
        for (auto &[num, count] : freq)
            buckets[count].push_back(num);

        ReturnType result;
        result.reserve(k);

        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i)
        {
            for (auto num : buckets[i])
            {
                result.push_back(num);
                if (result.size() == k)
                    break;
            }
        }

        return result;
    }
};