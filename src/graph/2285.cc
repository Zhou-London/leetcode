/* Maximum total importance of roads */
// * Medium

#include <numeric>
#include <vector>

using namespace std;

class Solution
{
  public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<long long> degree(n, 0);

        for (auto &e : roads)
        {
            degree[e[0]]++;
            degree[e[1]]++;
        }

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return degree[a] < degree[b]; });

        vector<long long> value(n, 0);
        for (int i = 0; i < n; ++i)
            value[idx[i]] = i + 1;

        long long total = 0;
        for (auto &e : roads)
            total += value[e[0]] + value[e[1]];

        return total;
    }
};