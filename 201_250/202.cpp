// 抽象题目。。。

#include <cmath>
#include <string>
#include <unordered_set>

class Solution {
    int calculateSumOfSquareOfAllNums(int a) {
        std::string s = std::to_string(a);
        int sum = 0;
        for (auto& x : s) {
            sum += std::pow(x - '0', 2);
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        std::unordered_set<int> s;

        while (true) { // 使用 while 循环不断计算平方和
            n = calculateSumOfSquareOfAllNums(n);
            if (n == 1) { // 判断平方和是否为 1
                return true;
            }
            if (s.count(n)) { // 判断平方和是否已经出现过
                return false;
            }
            s.insert(n); // 将平方和加入集合
        }
    }
};
