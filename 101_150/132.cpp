//
// Created by janeuler on 2024/8/11.
//
# include <string>
# include <limits>
# include <iostream>

class Solution {
public:
    static int ans;

    static int minCut(std::string s) {
        ans = std::numeric_limits<int>::max();
        if (s.empty()) return ans;

        int cur = 0;
        findMin(s, cur);
        return ans;
    }

private:
    static void findMin(std::string s, int &cur) {
        if (s.empty()) {
            ans = std::min(cur, ans);
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == s[0]) {
                std::string part = s.substr(0, i + 1);
                std::string rev_part(part.rbegin(), part.rend());
                if (part == rev_part) {
                    cur++;
                    findMin(s.substr(i + 1), cur);
                    cur--;
                }
            }
        }
    }
};
