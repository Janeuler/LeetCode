#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &numbers, int target)
    {
        int l = 0, r = numbers.size() - 1;
        int sum = numbers[l] + numbers[r];
        while (l < r)
        {
            sum = numbers[l] + numbers[r];
            if (sum == target)
            {
                return {l + 1, r + 1};
            }
            if (sum < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return {};
    }
};