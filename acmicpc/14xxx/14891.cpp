#include <iostream>
#include <algorithm>

using namespace std;

string str;
int G[5][10];
int K;
int N, D;
int R[5];

void F(int n, int d) {
  R[n] = 1;
  if(n-1 >= 1 && !R[n-1] && G[n][7] != G[n-1][3]) F(n-1, -d);
  if(n+1 <= 4 && !R[n+1] && G[n][3] != G[n+1][7]) F(n+1, -d);

  if(d > 0) {
    for(int i = 8; i >= 1; i--) {
      G[n][i+1] = G[n][i];
    }
    G[n][1] = G[n][9];
  } else {
    for(int i = 1; i <= 8; i++) {
      G[n][i-1] = G[n][i];
    }
    G[n][8] = G[n][0];
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i = 1; i <= 4; i++) {
    cin >> str;
    for(int j = 1; j <= 8; j++) {
      G[i][j] = str[j-1] - '0';
    }
  }
  cin >> K;
  for(int i = 1; i <= K; i++) {
    for(int i = 1; i <= 4; i++) {
      R[i] = 0;
    }
    cin >> N >> D;
    F(N, D);
  }

  cout << (G[1][1]?1:0) + (G[2][1]?2:0) + (G[3][1]?4:0) + (G[4][1]?8:0);

  return 0;
}