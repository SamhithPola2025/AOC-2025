#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("day09/input.txt");
    if (!fin.is_open()) {
        cerr << "could not open input.txt\n";
        return 1;
    }

    vector<pair<long long,long long>> pts;
    string line;

    while (getline(fin, line)) {
        if (line.empty()) continue;

        long long x, y;
        char comma;
        stringstream ss(line);
        ss >> x >> comma >> y;

        pts.emplace_back(x, y);
    }

    auto part1 = [&](const vector<pair<long long,long long>>& p){
        long long best = 0;
        int m = p.size();
        for (int i = 0; i < m; ++i) {
            for (int j = i+1; j < m; ++j) {
                long long area = (llabs(p[i].first - p[j].first)+1) * (llabs(p[i].second - p[j].second)+1);
                best = max(best, area);
            }
        }
        return best;
    };

    auto part2 = [&](const vector<pair<long long,long long>>& p){
        int m = p.size();
        struct Edge { long long x1,y1,x2,y2; };
        vector<Edge> edges;
        edges.reserve(m);
        for (int i = 0; i < m; ++i) {
            auto [x1,y1] = p[i];
            auto [x2,y2] = p[(i+1)%m];
            edges.push_back({x1,y1,x2,y2});
        }

        auto onEdge = [&](long long x, long long y, const Edge& e){
            if (e.x1 == e.x2) return x == e.x1 && min(e.y1,e.y2) <= y && y <= max(e.y1,e.y2);
            return y == e.y1 && min(e.x1,e.x2) <= x && x <= max(e.x1,e.x2);
        };

        auto inside = [&](long long x, long long y){
            int c = 0;
            for (auto &e : edges) {
                if (onEdge(x,y,e)) return true;
                long long y1=e.y1, y2=e.y2;
                if ((y1 > y) != (y2 > y)) {
                    if (e.x1 == e.x2 && e.x1 > x) c ^= 1;
                }
            }
            return c==1;
        };

        auto rectOK = [&](long long x1, long long y1, long long x2, long long y2){
            long long rx1=min(x1,x2), rx2=max(x1,x2);
            long long ry1=min(y1,y2), ry2=max(y1,y2);
            if (!inside(rx1, ry1) || !inside(rx1, ry2) || !inside(rx2, ry1) || !inside(rx2, ry2)) return false;
            for (auto &e : edges) {
                long long ax=e.x1, ay=e.y1, bx=e.x2, by=e.y2;
                if (ax==bx) {
                    if (rx1 < ax && ax < rx2) {
                        long long lo=min(ay,by), hi=max(ay,by);
                        if (max(ry1, lo) < min(ry2, hi)) return false;
                    }
                } else {
                    if (ry1 < ay && ay < ry2) {
                        long long lo=min(ax,bx), hi=max(ax,bx);
                        if (max(rx1, lo) < min(rx2, hi)) return false;
                    }
                }
            }
            return true;
        };

        long long best = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = i+1; j < m; ++j) {
                if (p[i].first == p[j].first || p[i].second == p[j].second) continue;
                if (!rectOK(p[i].first, p[i].second, p[j].first, p[j].second)) continue;
                long long area = (llabs(p[i].first - p[j].first)+1) * (llabs(p[i].second - p[j].second)+1);
                best = max(best, area);
            }
        }
        return best;
    };

    cout << part1(pts) << "\n" << part2(pts) << "\n";
    return 0;
}
