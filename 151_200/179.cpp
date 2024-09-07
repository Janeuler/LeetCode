#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::string largestNumber(std::vector<int> &nums)
    {
        std::string ans = "";
        std::vector<std::string> str;
        for (auto &x : nums)
        {
            str.push_back(std::to_string(x));
        }

        // std::sort(str.begin(), str.end(), compareNumbers);

        std::sort(str.begin(), str.end(), [](const std::string &s1, const std::string &s2)
                  { return (s1 + s2) > (s2 + s1); });
        if (str[0] == "0")
            return "0";

        for (auto &s : str)
        {
            ans += s;
        }
        return ans;
    }

    // private:
    //     bool compareNumbers(std::string &num1, std::string &num2)
    //     {
    //         int n = std::min(num1.size(), num2.size());
    //         return num1.substr(n) >= num2.substr(n);
    //     }
};