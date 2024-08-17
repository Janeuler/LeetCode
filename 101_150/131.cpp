//
// Created by janeuler on 2024/8/11.
//
# include <vector>
# include <string>

class Solution {
public:
    std::vector<std::vector<std::string> > partition(std::string s) {
        std::vector<std::vector<std::string> > ans;
        if (s.empty()) return ans;
        std::vector<std::string> temp;
        partition(ans, s, temp);
        return ans;
    }

private:
    void partition(std::vector<std::vector<std::string> > &ans, std::string s, std::vector<std::string> &temp) {
        if (s.empty()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            std::string part = s.substr(0, i + 1);
            std::string rev_part(part.rbegin(), part.rend());
            if (part == rev_part) {
                temp.push_back(part);
                partition(ans, s.substr(i + 1), temp);
                temp.pop_back();
            }
        }
    }
};
