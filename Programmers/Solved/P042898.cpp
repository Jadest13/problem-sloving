#include <bits/stdc++.h>

#define MAX 101
#define MOD 1000000007

using namespace std;
using PII = pair<int, int>;
using PIPII = pair<int, PII>;

int Visit[MAX][MAX];
int Dist[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int mn = 100001;
    priority_queue<PIPII, vector<PIPII>, greater<PIPII>> PQ;
    for(auto a : puddles) {
        Visit[a[0]][a[1]] = 1;
    }
    
    PQ.push({1, {1, 1}});
    Visit[1][1] = 1;
    Dist[1][1] = 1;
    while(!PQ.empty()) {
        int pn = PQ.top().first;
        int px = PQ.top().second.first;
        int py = PQ.top().second.second;
        PQ.pop();
        
        if(pn > mn) continue;
        if(px == m && py == n) {
            mn = pn;
            break;
        }
        
        for(int d = 0; d < 4; d++) {
            int nx = px + dx[d];
            int ny = py + dy[d];
            if(nx < 1 || nx > m || ny < 1 || ny > n) continue;
            if(Dist[nx][ny] == pn+1) {
                Visit[nx][ny] += Visit[px][py];
                Visit[nx][ny] %= MOD;
            }
            if(Visit[nx][ny]) continue;
            
            PQ.push({pn+1, {nx, ny}});
            Visit[nx][ny] = Visit[px][py];
            Dist[nx][ny] = pn+1;
        }
    }
    
    answer = Visit[m][n];
    
    return answer;
}