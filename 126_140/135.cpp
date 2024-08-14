//
// Created by janeuler on 2024/8/13.
//
# include <vector>


class Solution {
public:
    int candy(std::vector<int> &ratings) {
        std::vector<int> v(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                v[i] = v[i - 1] + 1;
            }
        }

        for (int j = ratings.size() - 2; j >= 0; j--) {
            if (ratings[j] > ratings[j + 1]) {
                v[j] = std::max(v[j], v[j + 1] + 1);
            }
        }

        int ans = 0;
        for (auto &x: v) {
            ans += x;
        }
        return ans;
    }
};
