#include <bits/stdc++.h>

#define MAX 10001

using namespace std;
using PSS = pair<string, string>;

int DFS(map<string, vector<string>> MP, string str, int N, int n, vector<string> *answer) {
    if(n == N) return 1;
    
    sort(MP[str].begin(), MP[str].end(), [](string a, string b) {
        return a < b;
    });
    for(int i = 0; i < MP[str].size(); i++) {
        string next = MP[str][i];
        answer->push_back(next);
        MP[str].erase(MP[str].begin()+i);
        if(DFS(MP, next, N, n+1, answer)) {
            return 1;
        }
        answer->pop_back();
        MP[str].insert(MP[str].begin()+i, next);
    }
    return 0;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    map<string, vector<string>> MP;
    for(auto a : tickets) {
        MP[a[0]].push_back(a[1]);
    }
    
    for(auto a : MP) {
        sort(a.second.begin(), a.second.end(), [](string a, string b) {
            return a < b;
        });
    }
    
    answer.push_back("ICN");
    DFS(MP, "ICN", tickets.size(), 0, &answer);
    
    return answer;
}