//
// Created by janeuler on 2024/8/14.
// 使用异或运算，a xor b xor b = a, when a == 0
//
# include <vector>

class Solution {
public:
    int singleNumber(std::vector<int> &nums) {
        int single = 0;
        for (auto &x: nums) {
            single = single xor x;
        }

        return single;
    }
};
