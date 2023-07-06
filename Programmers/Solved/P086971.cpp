#include <bits/stdc++.h>

#define MAX 101

using namespace std;

vector<int> E[MAX];
int Visit[MAX];
int res = MAX;

int DFS(int N, int n) {
    int ret = 1;
    Visit[n] = 1;
    for(auto a : E[n]) {
        if(Visit[a]) continue;
        ret += DFS(N, a);
    }
    res = min(res, abs(ret - (N-ret)));
    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    for(auto a : wires) {
        E[a[0]].push_back(a[1]);
        E[a[1]].push_back(a[0]);
    }
    
    DFS(n, 1);
    answer = res;
    
    return answer;
}