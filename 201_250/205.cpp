#include <string>
#include <unordered_map>

class Solution
{
public:
    bool isIsomorphic(std::string s, std::string t)
    {
        std::unordered_map<char, char> map1;
        std::unordered_map<char, char> map2;
        int index = 0;
        int n = s.size();
        while (index < n)
        {
            if (map1.find(s[index]) == map1.end())
            {
                map1[s[index]] = t[index];
            }
            if (map2.find(t[index]) == map2.end())
            {
                map2[t[index]] = s[index];
            }

            if (map1[s[index]] != t[index] || map2[t[index]] != s[index])
                return false;

            index++;
        }
        return true;
    }
};