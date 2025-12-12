// FINAL STRETCH WOOHOOO
// NO PART 2 FOR THIS ONE

#include <bits/stdc++.h>
using namespace std;

struct Shape {
    vector<string> grid;
    int width, height;
};

struct Region {
    int width, height;
    vector<int> present_counts;
};

vector<string> rotate90(const vector<string> &g) {
    int h = g.size(), w = g[0].size();
    vector<string> res(w, string(h, '.'));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            res[j][h-1-i] = g[i][j];
    return res;
}

vector<string> flipH(const vector<string> &g) {
    vector<string> res = g;
    for (auto &row : res) reverse(row.begin(), row.end());
    return res;
}

vector<string> flipV(const vector<string> &g) {
    vector<string> res = g;
    reverse(res.begin(), res.end());
    return res;
}

set<vector<string>> all_variants(const vector<string> &g) {
    set<vector<string>> s;
    vector<string> cur = g;
    for (int r = 0; r < 4; r++) {
        cur = rotate90(cur);
        s.insert(cur);
        s.insert(flipH(cur));
        s.insert(flipV(cur));
    }
    return s;
}

bool solve_region(const vector<Shape> &shapes, vector<int> counts, int region_width, int region_height) {
    int region_area = region_width * region_height;
    int present_area = 0;
    
    for (int i = 0; i < counts.size(); i++) {
        int shape_area = 0;
        for (auto &row : shapes[i].grid) {
            for (char cell : row) {
                if (cell == '#') shape_area++;
            }
        }
        present_area += shape_area * counts[i];
    }
    
    return present_area <= region_area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cerr << "failed to open input.txt\n";
        return 1;
    }

    vector<Shape> shapes;
    vector<Region> regions;
    string line;
    Shape current_shape;
    
    while (getline(fin, line)) {
        if (line.empty()) continue;
        
        if (line.find('x') != string::npos && line.find(':') != string::npos) {
            if (!current_shape.grid.empty()) {
                current_shape.height = current_shape.grid.size();
                current_shape.width = current_shape.grid[0].size();
                shapes.push_back(current_shape);
                current_shape.grid.clear();
            }
            
            Region r;
            stringstream ss(line);
            string size_str;
            ss >> size_str;
            
            auto colon_pos = size_str.find(':');
            string dim_str = size_str.substr(0, colon_pos);
            auto x_pos = dim_str.find('x');
            
            r.width = stoi(dim_str.substr(0, x_pos));
            r.height = stoi(dim_str.substr(x_pos + 1));
            
            int count;
            while (ss >> count) {
                r.present_counts.push_back(count);
            }
            regions.push_back(r);
        } else if (line.find(':') != string::npos) {
            if (!current_shape.grid.empty()) {
                current_shape.height = current_shape.grid.size();
                current_shape.width = current_shape.grid[0].size();
                shapes.push_back(current_shape);
                current_shape.grid.clear();
            }
        } else {
            current_shape.grid.push_back(line);
        }
    }
    
    if (!current_shape.grid.empty()) {
        current_shape.height = current_shape.grid.size();
        current_shape.width = current_shape.grid[0].size();
        shapes.push_back(current_shape);
    }

    int total = 0;
    for (auto &r : regions) {
        if (solve_region(shapes, r.present_counts, r.width, r.height)) {
            total++;
        }
    }

    cout << total << "\n";
    return 0;
}
