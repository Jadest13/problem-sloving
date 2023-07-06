#include <bits/stdc++.h>

#define MAX 201

using namespace std;
using PII = pair<int, int>;
using PIPII = pair<int, PII>;

int M[MAX][MAX];
int Visit[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    for(auto a : rectangle) {
        int x = a[0]*2;
        int y = a[1]*2;
        int w = a[2]*2;
        int h = a[3]*2;
        for(int i = x; i <= w; i++) {
            for(int j = y; j <= h; j++) {
                if(i==x || i==w || j==y || j==h) {
                    M[i][j] += 1;
                } else {
                    M[i][j] += 3;
                }
            }
        }
    }
    
    queue<PIPII> Q;
    Q.push({0, {characterX*2, characterY*2}});
    Visit[characterX*2][characterY*2] = 1;
    while(!Q.empty()) {
        int pn = Q.front().first;
        int px = Q.front().second.first;
        int py = Q.front().second.second;
        
        Q.pop();
        if(px == itemX*2 && py == itemY*2) {
            answer = pn/2;
            break;
        }
        
        for(int d = 0; d < 4; d++) {
            int nx = px + dx[d];
            int ny = py + dy[d];
            if(M[nx][ny] <= 0 || M[nx][ny] > 2) continue;
            if(Visit[nx][ny]) continue;
            
            Q.push({pn+1, {nx, ny}});
            Visit[nx][ny] = 1;
        }
    }
    
    return answer;
}