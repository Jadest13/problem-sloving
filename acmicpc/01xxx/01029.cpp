#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 15+1

using namespace std;
using LL = long long;

int N;
string str;
int A[MAX][MAX];
int DP[1<<MAX][MAX][10];

int F(int v, int a, int p) {
  if(DP[v][a][p] != -1) return DP[v][a][p];
  
  DP[v][a][p] = 0;
  for(int i = 0; i < N; i++) {
    if(!(v & (1<<i)) && A[a][i+1] > p) {
      DP[v][a][p] = max(DP[v][a][p], F(v | (1<<i), i+1, A[a][i+1])+1);
    }
  }
  return DP[v][a][p];
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(DP, -1, sizeof(DP));

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> str;
    for(int j = 1; j <= N; j++) {
      A[i][j] = str[j-1] - '0';
    }
  }

  F(1, 1, 0);
  cout << DP[1][1][0] + 1;

  return 0;
}