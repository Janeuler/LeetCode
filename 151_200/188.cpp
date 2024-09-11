#include <vector>

class Solution
{
public:
    int maxProfit(int k, std::vector<int> &prices)
    {
        int n = prices.size();
        if (!n || !k)
            return 0;

        if (k >= n / 2)
        {
            int ans = 0;
            for (int i = 0; i < prices.size() - 1; i++)
            {
                if (prices[i + 1] > prices[i])
                {
                    ans += prices[i + 1] - prices[i];
                }
            }
            return ans;
        }

        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(prices.size(), 0));
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j < n; j++)
            {
                int maxProfit = 0;
                for(int k = )
            }
        }
    }
};