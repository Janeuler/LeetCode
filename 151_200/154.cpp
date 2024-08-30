//
// Created by janeuler on 2024/8/24.
//
# include <vector>

class Solution {
public:
    int findMin(std::vector<int> &nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int pivot = low + (high - low) / 2;

            while (low < high && nums[low] == nums[low + 1]) {
                low++;
            }
            while (high > low && nums[high] == nums[high - 1]) {
                high--;
            }

            if (nums[pivot] <= nums[high]) {
                high = pivot;
            } else {
                low = pivot + 1;
            }
        }

        return nums[low];
    }
};
