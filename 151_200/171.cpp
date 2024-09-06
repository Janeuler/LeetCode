#include <vector>
#include <string>

class Solution
{
public:
    int titleToNumber(std::string columnTitle)
    {
        int ans = 0;
        int i = 0;
        std::vector<int> v;
        for (int n = 0; n < columnTitle.size(); n++)
        {
            if (!n)
                v.push_back(1);
            else
                v.push_back(26 * v.back());
        }
        while (i < columnTitle.size())
        {
            ans += v[v.size() - 1 - i] * (columnTitle[i] - 'A' + 1);
            i++;
        }
        return ans;
    }
};