/* Longest path with different adjacent characters */
// ! Hard

#include <vector>

using namespace std;

class Solution
{
  public:
    int ans = 1;

    int dfs(int node, vector<vector<int>> &graph, string &s)
    {
        int max1 = 0, max2 = 0;

        for (int child : graph[node])
        {
            int children = dfs(child, graph, s);

            if (s[child] != s[node])
            {
                if (children > max1)
                {
                    max2 = max1;
                    max1 = children;
                }
                else if (children > max2)
                {
                    max2 = children;
                }
            }
        }

        ans = max(ans, 1 + max1 + max2);

        return 1 + max1;
    }
    int longestPath(vector<int> &parent, string s)
    {
        int n = parent.size();
        vector<vector<int>> graph(n);
        for (int i = 1; i < n; ++i)
            graph[parent[i]].push_back(i);

        dfs(0, graph, s);
        return ans;
    }
};