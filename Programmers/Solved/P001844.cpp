#include<bits/stdc++.h>

#define MAX 101

using namespace std;

int Visit[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size();
    int m = maps[0].size();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(maps[i-1][j-1] == 0) Visit[i][j] = -1;
        }
    }
    
    queue<pair<int, pair<int, int>>> Q;
    Q.push({1, {1, 1}});
    Visit[1][1] = 1;
    while(!Q.empty()) {
        int pn = Q.front().first;
        int px = Q.front().second.first;
        int py = Q.front().second.second;
        
        Q.pop();
        
        if(px == n && py == m) {
            answer = pn;
            break;
        }
        
        for(int d = 0; d < 4; d++) {
            int nx = px + dx[d];
            int ny = py + dy[d];
            
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(Visit[nx][ny]) continue;
            Q.push({pn+1, {nx, ny}});
            Visit[nx][ny] = 1;
        }
    }
    
    return answer;
}