#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define INF 1e9

using namespace std;

int N;
int W[16][16];
int DP[16][1 << 16];
int R;

int DFS(int x, int b) {
  if(b == (1<<N)-1) {
    if(!W[x][0]) return INF;
    else return W[x][0];
  }

  if(DP[x][b] != -1) return DP[x][b];
  DP[x][b] = INF;

  for(int i = 0; i < N; i++) {
    if(!W[x][i]) continue;
    if(b & (1<<i)) continue;

    DP[x][b] = min(DP[x][b], W[x][i]+DFS(i, b | (1<<i)));
  }

  return DP[x][b];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i = 0; i < 16; i++) {
    for(int j = 0; j < 1<<16; j++) {
      DP[i][j] = -1;
    }
  }

  cin >> N;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> W[i][j];
    }
  }

  cout << DFS(0, 1);

  return 0;
}