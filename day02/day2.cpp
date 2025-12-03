#include <bits/stdc++.h>
using namespace std;

bool isRepeatedTwice(const string& s) {
    int n = s.size();
    for (int len = 1; len <= n/2; len++) {
        if (n != len*2) continue; // must be exactly 2 repeats
        string p = s.substr(0, len);
        if (s.substr(len, len) == p) return true;
    }
    return false;
}

bool isRepeatedAtLeast2(const string& s) {
    int n = s.size();
    for (int len = 1; len <= n/2; len++) {
        if (n % len != 0) continue; // must divide evenly
        string p = s.substr(0, len);
        bool ok = true;
        for (int i = 0; i < n; i += len) {
            if (s.substr(i, len) != p) {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    return false;
}

long solvePart1(const string& range) {
    long sum = 0;
    long dash = range.find('-');
    long a = stol(range.substr(0, dash));
    long b = stol(range.substr(dash + 1));

    for (long x = a; x <= b; x++) {
        string s = to_string(x);
        if (isRepeatedTwice(s)) sum += x;
    }
    return sum;
}

long solvePart2(const string& range) {
    long sum = 0;
    long dash = range.find('-');
    long a = stol(range.substr(0, dash));
    long b = stol(range.substr(dash + 1));

    for (long x = a; x <= b; x++) {
        string s = to_string(x);
        if (isRepeatedAtLeast2(s)) sum += x;
    }
    return sum;
}

int main() {
    ifstream file("day02/day2input.txt");
    string line;

    if (getline(file, line)) {
        stringstream ss(line);
        string range;
        long total1 = 0, total2 = 0;

        while (getline(ss, range, ',')) {
            total1 += solvePart1(range);
            total2 += solvePart2(range);
        }

        cout << total1 << endl;
        cout << total2 << endl;
    }
    return 0;
}
