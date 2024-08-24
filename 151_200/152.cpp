//
// Created by janeuler on 2024/8/22.
//
# include <vector>

class Solution {
public:
    int maxProduct(std::vector<int> &nums) {
        int curMin = nums[0], curMax = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int temp = curMin;
            curMin = std::min(nums[i], std::min(nums[i] * curMin, nums[i] * curMax));
            curMax = std::max(nums[i], std::max(nums[i] * curMax, nums[i] * temp));
            ans = std::max(curMax, ans);
        }

        return ans;
    }
};
