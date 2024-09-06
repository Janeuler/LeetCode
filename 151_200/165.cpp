#include <string>

class Solution
{
public:
    int compareVersion(std::string version1, std::string version2)
    {
        int n1 = version1.size(), n2 = version2.size();
        int p1 = 0, p2 = 0;
        while (p1 < n1 || p2 < n2)
        {
            int num1 = 0, num2 = 0;
            while (p1 < n1 && version1[p1] != '.')
            {
                num1 = 10 * num1 + version1[p1] - '0';
                p1++;
            }

            while (p2 < n2 && version2[p2] != '.')
            {
                num2 = 10 * num2 + version2[p2] - '0';
                p2++;
            }
            if (num1 > num2)
                return 1;
            else if (num1 < num2)
                return -1;
            p1++;
            p2++;
        }
        return 0;
    }

    // private:
    //     int com(const std::string &s1, const std::string &s2)
    //     {
    //         int num1 = 0, num2 = 0;
    //         for (auto &x : s1)
    //         {
    //             num1 = 10 * num1 + x - '0';
    //         }
    //         for (auto &y : s2)
    //         {
    //             num2 = 10 * num2 + y - '0';
    //         }
    //         if (num1 > num2)
    //             return 1;
    //         i·f (num1 < num2)
    //             return -1;
    //         return 0;
    //         // return num1 > num2 ? 1 : (num1 < num2 ? -1 : 0);
    //     }
};