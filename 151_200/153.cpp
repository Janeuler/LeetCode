//
// Created by janeuler on 2024/8/24.
//
# include <vector>

class Solution {
public:
    int findMin(std::vector<int> &nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int privo = l + (r - l) / 2;
            if (nums[privo] < nums[r]) {
                r = privo; // 需要考虑如下情况：可能存在nums[privo] == min(nums)，此时不应该-1，因此应该设置为r = privo;
            } else {
                l = privo + 1;
            }
        }

        return nums[l];
    }
};
