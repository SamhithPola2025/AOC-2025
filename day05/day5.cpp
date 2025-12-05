#include <bits/stdc++.h>
using namespace std;

pair<long long,long long> parseRange(const string &s){
    auto i=s.find('-');
    return {stoll(s.substr(0,i)),stoll(s.substr(i+1))};
}

int part1(const vector<pair<long long,long long>> &ranges, const vector<long long> &ids){
    int cnt=0;
    for(auto x:ids) for(auto r:ranges) if(x>=r.first && x<=r.second){cnt++; break;}
    return cnt;
}

long long part2(vector<pair<long long,long long>> ranges){
    sort(ranges.begin(),ranges.end());
    long long ans=0,s=-1,e=-1;
    for(auto [a,b]:ranges){
        if(a>e){ if(e!=-1) ans+=e-s+1; s=a; e=b; }
        else e=max(e,b);
    }
    if(e!=-1) ans+=e-s+1;
    return ans;
}

int main(){
    ifstream f("day05/input.txt");
    string l;
    vector<pair<long long,long long>> ranges;
    vector<long long> ids;
    bool ing=false;
    while(getline(f,l)){
        if(l.empty()){ing=true; continue;}
        if(ing) ids.push_back(stoll(l));
        else ranges.push_back(parseRange(l));
    }
    cout<<part1(ranges,ids)<<"\n"<<part2(ranges)<<"\n";
}
