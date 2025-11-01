/* Add edges to make degrees of all nodes even */
// ! Hard

#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool isPossible(int n, vector<vector<int>> &edges)
    {
        vector<int> deg(n + 1, 0);
        unordered_set<long long> edgeSet;

        // Kinda like a hash func
        auto key = [&](int a, int b) {
            if (a > b)
                swap(a, b);
            return (long long)a * 1000000 + b;
        };

        for (auto &e : edges)
        {
            int a = e[0], b = e[1];
            deg[a]++, deg[b]++;
            edgeSet.insert(key(a, b));
        }

        vector<int> odd;
        for (int i = 1; i <= n; ++i)
            if (deg[i] % 2 == 1)
                odd.push_back(i);

        // 3 Possible Cases:
        if (odd.empty())
            return true;

        if (odd.size() == 2)
        {
            int a = odd[0], b = odd[1];

            if (!edgeSet.count(key(a, b)))
                return true;
            for (int i = 1; i <= n; ++i)
            {
                if (i == a || i == b)
                    continue;
                if (!edgeSet.count(key(a, i)) && !edgeSet.count(key(b, i)))
                    return true;
            }
            return false;
        }

        if (odd.size() == 4)
        {
            vector<vector<int>> pairings = {{0, 1, 2, 3}, {0, 2, 1, 3}, {0, 3, 1, 2}};
            for (auto &p : pairings)
            {
                int a1 = odd[p[0]], b1 = odd[p[1]];
                int a2 = odd[p[2]], b2 = odd[p[3]];
                if (!edgeSet.count(key(a1, b1)) && !edgeSet.count(key(a2, b2)))
                    return true;
            }
            return false;
        }

        return false;
    }
};