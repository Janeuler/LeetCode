//
// Created by janeuler on 2024/8/22.
//
# include <algorithm>
# include <string>

class Solution {
public:
    std::string reverseWords(std::string s) {
        // 先去除首尾的括号
        int l = 0;
        while (l < s.size() && s[l] == ' ') {
            l++;
        }
        s.erase(0, l);
        l = 0;
        int r = s.size() - 1;
        while (r >= 0 && s[r] == ' ') {
            r--;
        }
        s.erase(r + 1, s.size() - (r + 1));

        while (l < s.size()) {
            if (s[l] == ' ' && s[l + 1] == ' ') {
                int start = l;
                int end = l;
                while (s[end] == ' ' && s[end + 1] == ' ') {
                    end++;
                }
                s.erase(start, end - start);
            } else if (isalpha(s[l])) {
                int start = l, end = l;
                while (end < s.size() && isalpha(s[end])) {
                    end++;
                }
                std::reverse(s.begin() + start, s.begin() + end);
                l = end;
            } else {
                l++;
            }
        }
        return s;
    }
};
