#include <bits/stdc++.h>

#define MAX 51

using namespace std;

typedef struct {
    int x, y;
} Point;

int Visit[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    vector<vector<vector<Point>>> S;
    vector<vector<Point>> T;
    int n = table.size();
    int m = table[0].size();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(table[i-1][j-1] == 0) {
                Visit[i][j] = 1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(Visit[i][j]) continue;
            
            int mnx = i, mny = j;
            int mxx = i, mxy = j;
            int mx = 0;
            int A[MAX][MAX];
            int B[MAX][MAX];
            
            queue<Point> Q;
            vector<Point> Fg;
            vector<vector<Point>> R;
            Q.push({i, j});
            Visit[i][j] = 1;
            while(!Q.empty()) {
                int px = Q.front().x;
                int py = Q.front().y;
                mnx = min(mnx, px);
                mny = min(mny, py);
                mxx = max(mxx, px);
                mxy = max(mxy, py);
                Fg.push_back({px, py});
                
                Q.pop();
                
                for(int d = 0; d < 4; d++) {
                    int nx = px + dx[d];
                    int ny = py + dy[d];
                    
                    if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                    if(Visit[nx][ny]) continue;
                    
                    Q.push({nx, ny});
                    Visit[nx][ny] = 1;
                }
            }
            
            mx = max(mxx-mnx, mxy-mny);
            
            for(int u = 0; u <= mx; u++) {
                for(int v = 0; v <= mx; v++) {
                    A[u][v] = 0;
                }
            }
            for(auto a : Fg) {
                A[a.x-mnx][a.y-mny] = 1;
            }
            
            for(int cnt = 1; cnt <= 4; cnt++) {
                for(int u = 0; u <= mx; u++) {
                    for(int v = 0; v <= mx; v++) {
                        B[u][mx-v] = A[v][u];
                    }
                }

                vector<Point> V;
                mnx = MAX;
                mny = MAX;
                for(int u = 0; u <= mx; u++) {
                    for(int v = 0; v <= mx; v++) {
                        A[u][v] = B[u][v];
                        if(A[u][v] == 1) {
                            mnx = min(mnx, u);
                            mny = min(mny, v);
                        }
                    }
                }
                for(int u = 0; u <= mx; u++) {
                    for(int v = 0; v <= mx; v++) {
                        A[u][v] = B[u][v];
                        if(A[u][v] == 1) {
                            V.push_back({u-mnx, v-mny});
                        }
                    }
                }
                
                sort(V.begin(), V.end(), [](Point a, Point b) {
                    if(a.x == b.x) return a.y < b.y;
                    else return a.x < b.x;
                });
                R.push_back(V);
            }
            S.push_back(R);
        }
    }
    
    n = game_board.size();
    m = game_board[0].size();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            Visit[i][j] = 0;
            if(game_board[i-1][j-1] == 1) {
                Visit[i][j] = 1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(Visit[i][j]) continue;
            
            int mnx = i, mny = j;
            int mxx = i, mxy = j;
            int mx = 0;
            int A[MAX][MAX];
            int B[MAX][MAX];
            
            queue<Point> Q;
            vector<Point> Fg;
            vector<vector<Point>> R;
            Q.push({i, j});
            Visit[i][j] = 1;
            while(!Q.empty()) {
                int px = Q.front().x;
                int py = Q.front().y;
                mnx = min(mnx, px);
                mny = min(mny, py);
                mxx = max(mxx, px);
                mxy = max(mxy, py);
                Fg.push_back({px, py});
                
                Q.pop();
                
                for(int d = 0; d < 4; d++) {
                    int nx = px + dx[d];
                    int ny = py + dy[d];
                    
                    if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                    if(Visit[nx][ny]) continue;
                    
                    Q.push({nx, ny});
                    Visit[nx][ny] = 1;
                }
            }
            
            mx = max(mxx-mnx, mxy-mny);
            
            for(int u = 0; u <= mx; u++) {
                for(int v = 0; v <= mx; v++) {
                    A[u][v] = 0;
                }
            }
            for(auto a : Fg) {
                A[a.x-mnx][a.y-mny] = 1;
            }
            
            vector<Point> V;
            for(int u = 0; u <= mx; u++) {
                for(int v = 0; v <= mx; v++) {
                    if(A[u][v] == 1) {
                        V.push_back({u, v});
                    }
                }
            }
            sort(V.begin(), V.end(), [](Point a, Point b) {
                if(a.x == b.x) return a.y < b.y;
                else return a.x < b.x;
            });
            T.push_back(V);
        }
    }
    
    for(auto a : S) {
        for(auto c : a[0]) {
                        cout << c.x << ", " << c.y << "\n";
        }
                    cout << "\n";
    }
    
    for(auto a : T) {
                    for(auto c : a) {
                        cout << c.x << ", " << c.y << "\n";
                    }
                    cout << "\n";
        for(int i = 0; i < S.size(); i++) {
            int flag = 0;
            if(S[i][0].size() != a.size()) continue;
            for(int j = 0; j < 4; j++) {
                int n = 0;
                for(int k = 0; k < a.size(); k++) {
                    if(a[k].x == S[i][j][k].x && a[k].y == S[i][j][k].y) n++;
                    else break;
                }
                if(n == a.size()) {
                    answer += n;
                    flag = 1;
                    break;
                }
            }
            if(flag) {
                S.erase(S.begin()+i);
                break;
            }
        }
    }
    
    
    return answer;
}