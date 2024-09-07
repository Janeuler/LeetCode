//
// Created by janeuler on 2024/8/24.
//
/* 一个极为基础的题目，然后有一个笨蛋写不出来，看了半个小时的答案才明白怎么回事。。。
思路如下：
*/

#include <vector>

class Solution
{
public:
    int calculateMinimumHP(std::vector<std::vector<int>> &dungeon)
    {
        std::vector<std::vector<int>> dp(dungeon.size() + 1, std::vector<int>(dungeon[0].size() + 1, INT_MAX));
        int m = dungeon.size(), n = dungeon[0].size();
        dp[m - 1][n] = 1;
        dp[m][n - 1] = 1;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--) 
            {
                int need = std::min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = need > 0 ? need : 1;
            }
        }

        return dp[0][0];
    }
};
