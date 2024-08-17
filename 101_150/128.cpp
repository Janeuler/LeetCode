# include <unordered_set>
# include <algorithm>
# include <vector>

class Solution {
public:
    int longestConsecutive(std::vector<int> &nums) {
        int longestStreak = 0;
        std::unordered_set num_set(nums.begin(), nums.end());

        for (auto &x: nums) {
            if (!num_set.count((x++) - 1)) {
                int currentNum = x;
                int currentStreak = 1;
                while (num_set.count(currentNum++)) {
                    currentStreak++;
                }
                longestStreak = std::max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
