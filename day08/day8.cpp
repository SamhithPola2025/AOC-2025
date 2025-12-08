#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y, z;
};

struct Edge {
    int u, v;
    long long dist2;
    bool operator<(const Edge &other) const {
        return dist2 < other.dist2;
    }
};

struct DSU {
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
};

long long dist2(const Point &a, const Point &b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    long long dz = a.z - b.z;
    return dx*dx + dy*dy + dz*dz;
}

long long part1(const vector<Point> &points, const vector<Edge> &edges) {
    int n = points.size();
    DSU dsu(n);
    
    int pairs = 0;
    for (auto &e : edges) {
        if (pairs == 1000) break;
        dsu.unite(e.u, e.v);
        pairs++;
    }
    
    map<int, long long> compSizes;
    for (int i = 0; i < n; ++i) {
        compSizes[dsu.find(i)] = dsu.size[dsu.find(i)];
    }
    
    vector<long long> sizes;
    for (auto &p : compSizes) {
        sizes.push_back(p.second);
    }
    sort(sizes.rbegin(), sizes.rend());
    
    long long result = 1;
    for (int i = 0; i < 3 && i < sizes.size(); ++i) {
        result *= sizes[i];
    }
    
    return result;
}

long long part2(const vector<Point> &points, const vector<Edge> &edges) {
    int n = points.size();
    DSU dsu(n);
    
    for (auto &e : edges) {
        int rootU = dsu.find(e.u);
        int rootV = dsu.find(e.v);
        
        if (rootU != rootV) {
            dsu.unite(e.u, e.v);
            
            if (dsu.size[dsu.find(0)] == n) {
                return (long long)points[e.u].x * points[e.v].x;
            }
        }
    }
    
    return -1;
}

int main() {
    ifstream fin("day08/input.txt");
    vector<Point> points;
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        int x, y, z;
        char comma;
        ss >> x >> comma >> y >> comma >> z;
        points.push_back({x, y, z});
    }

    int n = points.size();
    vector<Edge> edges;

    // Generate all edges
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            edges.push_back({i, j, dist2(points[i], points[j])});
        }
    }

    sort(edges.begin(), edges.end());

    cout << "Part 1: " << part1(points, edges) << "\n";
    cout << "Part 2: " << part2(points, edges) << "\n";
}
