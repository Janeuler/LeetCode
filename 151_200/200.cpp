#include <vector>

class Solution
{
private:
    void dfs(std::vector<std::vector<char>> &grid, int x, int y)
    {
        grid[x][y] = '0';
        if (x + 1 < grid.size() && grid[x + 1][y] == '1')
            dfs(grid, x + 1, y);
        if (x - 1 >= 0 && grid[x - 1][y] == '1')
            dfs(grid, x - 1, y);
        if (y + 1 < grid[0].size() && grid[x][y + 1] == '1')
            dfs(grid, x, y + 1);
        if (y - 1 >= 0 && grid[x][y - 1] == '1')
            dfs(grid, x, y - 1);
    }

public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        int ans = 0;
        int nr = grid.size();
        int nc = grid[0].size();
        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < nc; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};