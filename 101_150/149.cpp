#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric> // for std::gcd

using namespace std;

// 结构体表示分数
struct Fraction {
    int numerator;
    int denominator;

    Fraction(int num, int den) : numerator(num), denominator(den) {
        simplify();
    }

    // 简化分数
    void simplify() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            // 保证分母为正数
            numerator *= -1;
            denominator *= -1;
        }
    }

    // 重载运算符 ==，用于比较分数是否相等
    bool operator==(const Fraction &other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }
};

// 自定义哈希函数，用于 unordered_map
namespace std {
    template<>
    struct hash<Fraction> {
        size_t operator()(const Fraction &f) const {
            return hash<int>()(f.numerator) ^ hash<int>()(f.denominator);
        }
    };
}

class Solution {
public:
    int maxPoints(vector<vector<int> > &points) {
        int n = points.size();
        if (n < 3) return n;

        int maxCount = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<Fraction, int> slopeCount;
            int samePoint = 1;
            int localMax = 0;

            for (int j = i + 1; j < n; ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    samePoint++;
                } else {
                    // 使用分数表示斜率
                    Fraction slope(points[j][1] - points[i][1], points[j][0] - points[i][0]);

                    slopeCount[slope]++;
                    localMax = max(localMax, slopeCount[slope]);
                }
            }

            maxCount = max(maxCount, localMax + samePoint);
        }

        return maxCount;
    }
};
