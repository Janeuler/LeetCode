// 从5开始考虑，如果阶乘中的因子包含了5，则每个因子计数一次，如果包含了25，则再次计数一次，这样就相当于因子中如果该因子包含了5，计数一次，
// 如果包含的是25，则计数两次，以此类推。


class Solution
{
public:
    int trailingZeroes(int n)
    {
        int i = 5;
        int res = 0;
        while (i <= n)
        {
            res += n / i;
            i *= 5;
        }
        return res;
    }
};