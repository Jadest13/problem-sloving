#include <bits/stdc++.h>

#define MAX 2501
#define INF 1e9+7

using namespace std;

string str;
int N;
int DP[MAX][MAX];
int R[MAX];

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str;
  N = str.length();
  str = " " + str;

  for(int i = 0; i < N; i++) {
    for(int j = 1; j + i <= N; j++) {
      if(i == 0) {
        DP[j][j] = 1;
        continue;
      }
      if(str[j] == str[j+i] && (DP[j+1][j+i-1] || i == 1)) {
        DP[j][j+i] = 1;
      }
    }
  }

  R[0] = 0;
  for(int i = 1; i <= N; i++) {
    R[i] = INF;
    for(int j = 1; j <= i; j++) {
      if(DP[j][i] && R[i] > R[j-1]+1) {
        R[i] = R[j-1]+1;
      }
    }
  }

  cout << R[N];

  return 0;
}