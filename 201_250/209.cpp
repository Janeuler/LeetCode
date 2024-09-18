#include <vector>

class Solution
{
public:
    int minSubArrayLen(int target, std::vector<int> &nums)
    {
        int minL = 10000;

        int l = 0, r = 0;
        int n = nums.size();
        int sum = nums[0];
        while (r < n)
        {
            while (sum < target && r < n)
            {
                r++;
                if (r < n)
                    sum += nums[r];
            }

            while (sum >= target && l <= r)
            {
                int b = sum - nums[l];
                if (b >= target)
                {
                    sum -= nums[l];
                    l++;
                }
                else
                {
                    break;
                }
            }

            minL = std::min(minL, r - l + 1);
            l++;
        }

        return minL < 10000 ? 0 : minL;
    }
};