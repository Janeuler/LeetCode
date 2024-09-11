class Solution
{
public:
    int hammingWeight(int n)
    {
        int count = 0;
        int a = n;
        while (a)
        {
            if (1 & a)
            {
                count++;
            }
            a >>= 1;
        }

        return count;
    }
};