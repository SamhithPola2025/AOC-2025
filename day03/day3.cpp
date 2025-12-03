#include <bits/stdc++.h>
using namespace std;

string pickK(const string& s, int k) {
    int n = s.size();
    int start = 0;
    string result;
    result.reserve(k);

    while (k > 0) {
        int end = n - k;
        char best = '0';
        int bestPos = start;

        for (int i = start; i <= end; i++) {
            if (s[i] > best) {
                best = s[i];
                bestPos = i;
            }
        }

        result.push_back(best);
        start = bestPos + 1;
        k--;
    }

    return result;
}

long long part1(const vector<string>& lines) {
    long long total = 0;
    for (auto& line : lines) {
        string chosen = pickK(line, 2);  // choose 2 digits
        total += stoll(chosen);
    }
    return total;
}

long long part2(const vector<string>& lines) {
    long long total = 0;
    for (auto& line : lines) {
        string chosen = pickK(line, 12); // choose 12 digits
        total += stoll(chosen);
    }
    return total;
}

int main() {
    ifstream file("day03/day3input.txt");
    vector<string> lines;
    string line;

    while (getline(file, line)) {
        if (!line.empty()) lines.push_back(line);
    }

    cout << "part 1: " << part1(lines) << "\n";
    cout << "part 2: " << part2(lines) << "\n";
}
