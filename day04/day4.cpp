#include <bits/stdc++.h>
using namespace std;

int part1(const vector<string>& grid) {
    const int h = grid.size();
    const int w = grid[0].size();
    int tar = 0;
    vector<pair<int, int>> dirs = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };
    for (int r = 0; r < h; ++r) {
        for (int t = 0; t < w; ++t) {
            if (grid[r][t] != '@') continue;

            int count = 0;
            for (const auto& dir : dirs) {
                int dr = dir.first;
                int dc = dir.second;
                int nr = r + dr;
                int nc = t + dc;
                if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                    if (grid[nr][nc] == '@') count++;
                }
            }

            if (count < 4) tar++;
        }
    }

    return tar;
}

int part2(vector<string> grid) {
    int total = 0;
    bool changed = true;
    vector<pair<int,int>> dirs = {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1},         {0,1},
        {1,-1}, {1,0}, {1,1}
    };

    while (changed) {
        changed = false;
        vector<pair<int,int>> toRemove;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] != '@') continue;
                int cnt = 0;
                for (auto [dr,dc] : dirs) {
                    int nr = r+dr, nc = c+dc;
                    if (nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]=='@')
                        cnt++;
                }
                if (cnt<4) toRemove.push_back({r,c});
            }
        }
        for (auto [r,c] : toRemove) {
            grid[r][c] = '.';
            total++;
            changed = true;
        }
    }
    return total;
}

int main() {
    fstream file("day04/input.txt");
    vector<string> grid;
    string line;
    while (getline(file, line)) {
        grid.push_back(line);
    }
    int ans1 = part1(grid);
    cout << "Part 1: " << ans1 << endl;
    int ans2 = part2(grid);
    cout << "Part 2: " << ans2 << endl;
}