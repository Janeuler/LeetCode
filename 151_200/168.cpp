/* 从1开始，将阿拉伯数字映射为对应的Excel的字母，将其看作是mod26的进制转换，注意该进制中没有0，因此，可以先将val - 1， 再对26进行取余，得到对应的
* 字母，然后    
*/

#include <string>
#include <algorithm>

class Solution
{
public:
    std::string convertToTitle(int columnNumber)
    {
        std::string ans = "";
        int val = columnNumber;
        while (val)
        {
            int a = (val - 1) % 26;
            ans += a + 'A';
            val = (val - a - 1) / 26;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};