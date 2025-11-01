/* Walls and gates */
// * Medium

#include <climits>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
  public:
    void wallsAndGates(vector<vector<int>> &rooms)
    {

        // init
        if (rooms.empty() || rooms[0].empty())
            return;
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;

        // start at each gate
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (rooms[i][j] == 0)
                {
                    q.emplace(i, j);
                }
            }
        }

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // trace the distance til blocked
        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            for (auto [dr, dc] : dirs)
            {
                int nr = r + dr;
                int nc = c + dc;
                if (nr < 0 || nc < 0 || nr >= m || nc >= n || rooms[nr][nc] != INT_MAX)
                    continue;

                rooms[nr][nc] = rooms[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
    }
};