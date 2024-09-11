#include <vector>

class Solution
{
public:
    int rob(std::vector<int> &nums)
    {

        if (nums.size() == 1)
            return nums[0];
        std::vector<int> n = nums;
        n.pop_back();

        std::vector<int> dp(n.size() + 1, 0);

        int index = 2;
        int size = n.size();
        dp[1] = n[0];
        while (index <= size)
        {
            dp[index] = std::max(dp[index - 2] + n[index - 1], dp[index - 1]);
            index++;
        }

        int res1 = dp[size];

        n = nums;
        n.erase(n.begin());

        index = 2;
        dp[1] = n[0];

        while (index <= size)
        {
            dp[index] = std::max(dp[index - 2] + n[index - 1], dp[index - 1]);
            index++;
        }

        return std::max(res1, dp[size]);
    }
};