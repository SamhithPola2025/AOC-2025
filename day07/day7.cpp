#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("day07/input.txt");
    vector<string> grid;
    string line;
    while (getline(file, line)) grid.push_back(line);

    int rows = grid.size();
    int cols = grid[0].size();
    int startCol = -1;
    for (int i = 0; i < cols; i++) {
        if (grid[0][i] == 'S') {
            startCol = i;
            break;
        }
    }

    map<pair<int,int>, long long> memo;
    
    function<long long(int, int)> countPaths = [&](int r, int c) -> long long {
        if (r >= rows || c < 0 || c >= cols) {
            if (r >= rows && c >= 0 && c < cols) {
                return 1;
            }
            return 0;
        }
        
        auto key = make_pair(r, c);
        if (memo.count(key)) {
            return memo[key];
        }
        
        char cell = grid[r][c];
        long long result = 0;
        
        if (cell == '^') {
            long long left = countPaths(r+1, c-1);
            long long right = countPaths(r+1, c+1);
            result = left + right;
        } else if (cell == '.' || cell == 'S') {
            result = countPaths(r+1, c);
        }
        
        memo[key] = result;
        return result;
    };
    
    long long totalTimelines = countPaths(0, startCol);
    
    cout << totalTimelines << "\n";
    
    return 0;
}
