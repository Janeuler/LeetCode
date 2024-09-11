#include <vector>

class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        std::vector<int> dp(nums.size() + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        int index = 2;
        int n = nums.size();
        while (index <= n)
        {
            dp[index] = std::max(dp[index - 2] + nums[index - 1], dp[index - 1]);
            index++;
        }
        return dp[n];
    }
};