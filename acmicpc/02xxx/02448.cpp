#include <bits/stdc++.h>

using namespace std;

int N;
char A[1025*6][1025*3];

void DFS(int x, int y, int n) {
  if(n == 3) {
    A[x][y] = '*';
    A[x-1][y+1] = A[x+1][y+1] = '*';
    for(int i = -2; i <= 2; i++) A[x+i][y+2] = '*';
    return;
  } else {
    int h = n/2;
    DFS(x, y, h);
    DFS(x-h, y+h, h);
    DFS(x+h, y+h, h);
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  
  for(int i = 1; i <= N*2+1; i++) {
    for(int j = 1; j <= N; j++) {
      A[i][j] = ' ';
    }
  }
  DFS(N, 1, N);
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N*2+1; j++) {
      cout << A[j][i];
    }
    cout << "\n";
  }

  return 0;
}