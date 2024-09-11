#include <vector>
class Solution
{
public:
    void rotate(std::vector<int> &nums, int k)
    {
        int n = nums.size();
        int a = k % nums.size();
        std::vector<int> s;
        for (int i = 0; i < a; i++)
        {
            s.push_back(nums[n - i - 1]);
        }

        for (int i = n - 1 - a; i >= 0; i--)
        {
            nums[i + a] = nums[i];
        }

        for (int i = 0; i < a; i++)
        {
            nums[i] = s[s.size() - 1 - i];
        }
    }
};