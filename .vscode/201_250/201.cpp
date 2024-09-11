/* 数字范围内按位与，查找公共字符前缀*/

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int shift = 0;
        int a = left, b = right;
        while (a < b)
        {
            a >>= 1;
            b >>= 1;
            shift++;
        }

        return a << shift;
    }
};