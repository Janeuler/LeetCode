#include <vector>

class Solution
{
public:
    int findPeakElement(std::vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l < r)
        {
            mid = l + r + (r - l) / 2;
            if (nums[mid] < nums[mid + 1])
            {
                l = mid + 1;
            }
            else
                r = mid;
        }
        return l;
    }
};