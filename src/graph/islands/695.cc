/* Max area of island. */
// * Medium

#include <vector>

using namespace std;

class Solution
{
  public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int max_area = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        auto dfs = [&](auto &&self, int r, int c) -> int {
            if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0)
                return 0;

            grid[r][c] = 0;

            int area = 1;

            area += self(self, r - 1, c);
            area += self(self, r + 1, c);
            area += self(self, r, c - 1);
            area += self(self, r, c + 1);

            return area;
        };

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == 1)
                {
                    int this_area = dfs(dfs, i, j);
                    max_area = max(max_area, this_area);
                }
            }
        }

        return max_area;
    }
};