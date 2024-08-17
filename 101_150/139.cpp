//
// Created by janeuler on 2024/8/16.
//

# include <vector>
# include <string>
# include <algorithm>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
        std::vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        int index = 1;

        while (index <= s.size()) {
            int i = 0;
            while (i < index) {
                if (dp[i]) {
                    std::string subStr = s.substr(i, index - i);
                    if (std::find(wordDict.begin(), wordDict.end(), subStr) != wordDict.end()) {
                        dp[index] = true;
                        break;
                    }
                }
                i++;
            }

            index++;
        }

        return dp[s.size()];
    }
};
