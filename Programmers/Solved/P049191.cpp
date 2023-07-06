#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX 101

using namespace std;

int visitW[MAX][MAX];
int visitL[MAX][MAX];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<int> win[MAX], lose[MAX];
    for(auto a : results) {
        win[a[0]].push_back(a[1]);
        lose[a[1]].push_back(a[0]);
    }
    
    for(int i = 1; i <= n; i++) {
        queue<int> Q;
        for(auto a : win[i]) {
            Q.push(a);
            visitW[i][a] = 1;
        }
        while(!Q.empty()) {
            int p = Q.front();
            Q.pop();
            
            for(auto a : win[p]) {
                if(visitW[i][a]) continue;
                win[i].push_back(a);
                Q.push(a);
                visitW[i][a] = 1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        queue<int> Q;
        for(auto a : lose[i]) {
            Q.push(a);
            visitL[i][a] = 1;
        }
        while(!Q.empty()) {
            int p = Q.front();
            Q.pop();
            
            for(auto a : lose[p]) {
                if(visitL[i][a]) continue;
                lose[i].push_back(a);
                Q.push(a);
                visitL[i][a] = 1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(win[i].size() + lose[i].size() == n-1) answer++;
    }
    
    return answer;
}