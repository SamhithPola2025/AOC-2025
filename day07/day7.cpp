#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

vector<string> grid;
int rows, cols;

long long part1() {
    long long splitCount = 0;
    set<pair<int,int>> visited;
    
    function<void(int, int)> countSplitsInPath = [&](int row, int col) {
        if (row >= rows || col < 0 || col >= cols) {
            return;
        }
        
        auto pos = make_pair(row, col);
        if (visited.count(pos)) {
            return;
        }
        visited.insert(pos);
        
        char cell = grid[row][col];
        
        if (cell == '^') {
            splitCount++;
            countSplitsInPath(row + 1, col - 1);
            countSplitsInPath(row + 1, col + 1);
        } else {
            countSplitsInPath(row + 1, col);
        }
    };
    
    int startCol = -1;
    for (int i = 0; i < cols; i++) {
        if (grid[0][i] == 'S') {
            startCol = i;
            break;
        }
    }
    
    countSplitsInPath(0, startCol);
    return splitCount;
}

long long part2() {
    map<pair<int,int>, long long> memo;
    
    function<long long(int, int)> countBalls = [&](int row, int col) -> long long {
        if (row >= rows) {
            if (col >= 0 && col < cols) {
                return 1;
            }
            return 0;
        }
        
        if (col < 0 || col >= cols) {
            return 0;
        }
        
        pair<int,int> pos = make_pair(row, col);
        if (memo.find(pos) != memo.end()) {
            return memo[pos];
        }
        
        char cell = grid[row][col];
        long long result = 0;
        
        if (cell == '^') {
            long long leftBalls = countBalls(row + 1, col - 1);
            long long rightBalls = countBalls(row + 1, col + 1);
            result = leftBalls + rightBalls;
        } else {
            result = countBalls(row + 1, col);
        }
        
        memo[pos] = result;
        return result;
    };
    
    int startCol = -1;
    for (int i = 0; i < cols; i++) {
        if (grid[0][i] == 'S') {
            startCol = i;
            break;
        }
    }
    
    return countBalls(0, startCol);
}

int main() {
    ifstream file("day07/input.txt");
    if (!file.is_open()) {
        cout << "Could not open file" << endl;
        return 1;
    }
    
    string line;
    while (getline(file, line)) {
        grid.push_back(line);
    }
    file.close();
    
    if (grid.empty()) {
        cout << "Grid is empty" << endl;
        return 1;
    }
    
    rows = grid.size();
    cols = grid[0].size();
    
    cout << "Part 1: " << part1() << endl;
    cout << "Part 2: " << part2() << endl;
    
    return 0;
}
