#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
using PII = pair<int, int>;

int s = 0;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();
    
    vector<PII> V;
    for(auto a : jobs) {
        V.push_back({a[0], a[1]});
    }
    
    for(int i = 1; i <= n; i++) {
        sort(V.begin(), V.end(), [](PII a, PII b) {
           if(a.first <= s && b.first <= s) {
               return a.second < b.second;
           } else {
               if(a.first == b.first) {
                   return a.second < b.second;
               } else return a.first < b.first;
           }
        });
        
        if(V[0].first <= s) {
            answer += s-V[0].first + V[0].second;
            s += V[0].second;
        } else {
            answer += V[0].second;
            s = V[0].first + V[0].second;
        }
        V.erase(V.begin());
    }
    
    return answer/n;
}