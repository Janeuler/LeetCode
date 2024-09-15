// Use Sieve of Eratosthenes to solve the problem

#include <vector>

class Solution
{
public:
    int countPrimes(int n)
    {
        std::vector<bool> v(n + 1, true);
        v[0] = false;
        v[1] = false;

        int index = 2;
        while (index < n + 1)
        {
            if (v[index])
            {
                int a = v[index];
                for (int i = a * a; i < n + 1; i *= i)
                {
                    v[i] = false;
                }
            }
        }

        int ans = 0;
        for (auto &x : v)
        {
            if (x)
                ans++;
        }
        return ans;
    }
};