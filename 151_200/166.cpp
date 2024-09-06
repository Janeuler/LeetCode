#include <unordered_map>
#include <string>
#define ll long long

class Solution
{
public:
    std::string fractionToDecimal(int numerator, int denominator)
    {
        std::string ans = "";
        ll numeratorLong = numerator, denominatorLong = denominator;
        if (numeratorLong / denominatorLong < 0)
        {
            ans += '-';
        }

        // 整数部分
        ll integerBuffer = numeratorLong / denominatorLong;
        ans += std::to_string(integerBuffer);

        // 小数部分
        std::unordered_map<ll, ll> map;
        ll decimalNum = numeratorLong % denominatorLong;
        if (!decimalNum)
            return ans;
        else
            ans += '.';

        std::string decimalBuffer = "";
        int index = 0;
        while (decimalNum)
        {
            decimalNum = 10 * decimalNum;
            ll reminder = decimalNum % denominatorLong;
            if (find(map.begin(), map.end(), reminder) != map.end())
            {
                decimalBuffer.insert(map[reminder], '(');
            }
            else
            {
                map.emplace(reminder, index);
            }
        }
    }
};