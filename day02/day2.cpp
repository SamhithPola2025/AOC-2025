#include <bits/stdc++.h>
using namespace std;

bool isRepeated(const std::string &s) {
    int n = s.size();
    for (int len = 1; len <= n / 2; ++len) {
        if (n % len != 0) continue;
        std::string pattern = s.substr(0, len);
        bool isValid = true;
        int repeatCount = 0;
        for (int i = 0; i < n; i += len) {
            if (s.substr(i, len) != pattern) {
                isValid = false;
                break;
            }
            repeatCount++;
        }
        if (isValid && repeatCount >= 2) return true;
    }
    return false;
}

long part1(const std::string &range) {
    long sum = 0;
    size_t dash = range.find('-');
    long a = std::stol(range.substr(0, dash));
    long b = std::stol(range.substr(dash + 1));
    for (long x = a; x <= b; x++) {
        if (isRepeated(std::to_string(x))) {
            sum += x;
        }
    }
    return sum;
}

long part2(const std::string &range) {
    long sum = 0;
    size_t dash = range.find('-');
    long a = std::stol(range.substr(0, dash));
    long b = std::stol(range.substr(dash + 1));
    for (long x = a; x <= b; x++) {
        std::string numStr = std::to_string(x);
        if (isRepeated(numStr)) {
            sum += x;
        }
    }
    return sum;
}

int main() {
    std::ifstream file("day02/day2input.txt");
    std::string line;
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string range;
        long totalSumPart1 = 0, totalSumPart2 = 0;
        while (std::getline(ss, range, ',')) {
            long rangeSum1 = part1(range);
            totalSumPart1 += rangeSum1;
            long rangeSum2 = part2(range);
            totalSumPart2 += rangeSum2;
        }
        std::cout << "Total Sum of Numbers (Part 1): " << totalSumPart1 << std::endl;
        std::cout << "Total Sum of Numbers that Repeat Twice or More (Part 2): " << totalSumPart2 << std::endl;
    }
    return 0;
}