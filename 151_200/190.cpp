#include <cstdint>

class Solution
{
public:
    std::uint32_t reverseBits(std::uint32_t n)
    {
        std::uint32_t a = n;
        int result = 0;
        for (int i = 0; i < 32; i++)
        {
            result |= ((a >> i) & 1) << (31 - i);
        }
        return result;
    }
};