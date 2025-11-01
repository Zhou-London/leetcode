/* Number of closed islands. */
// * Medium

#include <vector>

using namespace std;

class Solution
{
  public:
    int closedIsland(vector<std::vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        auto dfs = [&](auto &&self, int r, int c) -> bool {
            if (r < 0 || c < 0 || r >= rows || c >= cols)
                return false;

            if (grid[r][c] == 1)
                return true;

            grid[r][c] = 1;

            bool up = self(self, r - 1, c);
            bool down = self(self, r + 1, c);
            bool right = self(self, r, c + 1);
            bool left = self(self, r, c - 1);

            return up && down && left && right;
        };

        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c] == 0)
                {
                    if (dfs(dfs, r, c))
                    {
                        ++count;
                    }
                }
            }
        }

        return count;
    }
};