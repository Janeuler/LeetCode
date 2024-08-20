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
            int verticalPoints = 0; // 新增：统计垂直线上点的数量
            int localMax = 0;

            for (int j = i + 1; j < n; ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    samePoint++;
                } else if (points[i][0] == points[j][0]) { // 处理垂直线
                    verticalPoints++;
                } else {
                    // 使用分数表示斜率
                    Fraction slope(points[j][1] - points[i][1], points[j][0] - points[i][0]);

                    slopeCount[slope]++;
                    localMax = max(localMax, slopeCount[slope]);
                }
            }

            maxCount = max(maxCount, max(localMax, verticalPoints) + samePoint); // 更新最大值时考虑垂直线
        }

        return maxCount;
    }
};


//
// Created by janeuler on 2024/8/20.
//
// # include <vector>
// # include <functional>
// # include <unordered_map>
//
//
// struct Fraction {
//     int numerator;
//     int denominator;
//
//     Fraction(int num, int dem): numerator(num), denominator(dem) {
//         simplify();
//     }
//
//     void simplify() {
//         if (!denominator) {
//             numerator = 1;
//             return;
//         }
//         std::function<int(int, int)> gcd = [&gcd](int a, int b) {
//             return !b ? a : gcd(b, a % b);
//         };
//
//         int commonDivisor = gcd(numerator, denominator);
//         numerator /= commonDivisor;
//         denominator /= commonDivisor;
//     }
//
//     bool operator==(const Fraction &other) const {
//         return numerator * other.denominator == denominator * other.numerator;
//     }
// };
//
// namespace std {
//     template<>
//     struct hash<Fraction> {
//         size_t operator()(const Fraction &f) const {
//             return hash<int>()(f.numerator) * 31 + hash<int>()(f.denominator);
//         }
//     };
// }
//
// class Solution {
// public:
//     int maxPoints(std::vector<std::vector<int> > &points) {
//         if (points.size() < 3) return points.size();
//
//         int maxCount = 0;
//
//         for (int i = 0; i < points.size(); i++) {
//             int samePoints = 1;
//             int localMax = 0;
//             std::unordered_map<Fraction, int> slopeMap;
//             for (int j = i + 1; j < points.size(); j++) {
//                 if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
//                     samePoints++;
//                 } else {
//                     Fraction slope(points[j][0] - points[i][0], points[j][1] - points[i][1]);
//                     slopeMap[slope]++;
//                     localMax = std::max(localMax, slopeMap[slope]);
//                 }
//             }
//             maxCount = std::max(maxCount, localMax + samePoints);
//         }
//
//         return maxCount;
//     }
// };
