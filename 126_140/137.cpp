//
// Created by janeuler on 2024/8/14.
//
# include <vector>

class Solution {
public:
    int singleNumber(std::vector<int> &nums) {
        int ones = 0, twos = 0, threes = 0;
        for (int num: nums) {
            twos |= ones & num; // 首先更新twos
            ones ^= num; // 然后更新ones
            threes = ones & twos; // threes为同时在ones和twos中出现的
            ones &= ~threes; // 从ones中去除出现三次的
            twos &= ~threes; // 从twos中去除出现三次的
        }
        return ones; // ones中保存的就是只出现一次的数字
    }
};
