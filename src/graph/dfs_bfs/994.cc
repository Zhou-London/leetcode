/* Rotting oranges. */
// * Medium

#include <queue>
#include <vector>
using namespace std;

class Solution
{
  public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 2)
                {
                    q.emplace(i, j);
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        if (fresh == 0)
            return 0;

        int minutes = 0;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty())
        {
            int size = q.size();
            bool infected = false;

            for (int i = 0; i < size; ++i)
            {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : dirs)
                {
                    int nr = r + dr, nc = c + dc;
                    if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                        continue;
                    if (grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        fresh--;
                        infected = true;
                        q.emplace(nr, nc);
                    }
                }
            }
            if (infected)
                minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
