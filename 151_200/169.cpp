// 使用moore voting algorithm, 从vector中的第一个数字开始遍历，记count = 1，如果当前数字和candidate相同，则count++， 否则，count--，如果count<0
// 则将candidate重置为新的待选项， 直到遍历结束。

#include <vector>

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int candidate = nums[0];
        int count = 1;
        int i = 1;
        while (i < nums.size())
        {
            if (candidate == nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
            if (count < 0)
            {
                candidate = nums[i];
                count = 1;
            }
            i++;
        }
        return candidate;
    }
};