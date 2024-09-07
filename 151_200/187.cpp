#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s)
    {
        std::unordered_map<std::string, int> map;
        std::vector<std::string> ans;
        for (int i = 0; i < s.size(); i++)
        {
            if (i + 9 < s.size())
            {
                std::string temp = s.substr(i, 10);
                map[temp]++;
                if (map[temp] == 2)
                {
                    ans.push_back(temp);
                }
            }
            else
                break;
        }

        return ans;
    }
};