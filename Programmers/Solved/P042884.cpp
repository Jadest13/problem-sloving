#include <bits/stdc++.h>

using namespace std;
using PII = pair<int, int>;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<PII> V;
    int pos = -30001;
    for(auto a : routes) {
        V.push_back({a[0], a[1]});
    }
    sort(V.begin(), V.end(), [](PII a, PII b) {
        if(a.first == b.first) return a.second < b.second;
        else return a.first < b.first;
    });
    for(auto a : V) {
        if(a.first > pos) {
            answer++;
            pos = a.second;
        }
        pos = min(pos, a.second);
    }
    
    return answer;
}