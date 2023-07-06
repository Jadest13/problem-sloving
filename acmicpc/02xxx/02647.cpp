#include <bits/stdc++.h>

#define MAX 101
#define INF 1000000007

using namespace std;

int N;
string str;
int sum[2][MAX];
int DP[MAX][MAX][6];

void F(int L, int R) {
  if(R-L == 1) {
    DP[L][R][0] = 3;
    DP[L][R][1] = 1;
    return;
  }
  
  int ret = INF;
  if(sum[0][R-1] - sum[0][L] == sum[1][R-1] - sum[1][L]) {
    if(DP[L+1][R-1][0] == 0) F(L+1, R-1);
    DP[L][R][1] = DP[L+1][R-1][1] + 1;
    ret = DP[L+1][R-1][0] + 2 * DP[L][R][1] + (R-L);
    DP[L][R][2] = L;
    DP[L][R][3] = R;
    DP[L][R][4] = L+1;
    DP[L][R][5] = R-1;
  }

  for(int r = L+1; r < R; r+=2) {
    int l = r+1;
    if(sum[0][r] - sum[0][L-1] != sum[1][r] - sum[1][L-1]) continue;

    if(DP[L][r][0] == 0) F(L, r);
    if(DP[l][R][0] == 0) F(l, R);
    int tmp_h = max(DP[L][r][1], DP[l][R][1]);
    int tmp = DP[L][r][0] + DP[l][R][0];
    if(ret > tmp) {
      ret = tmp;
      DP[L][R][1] = tmp_h;
      DP[L][R][2] = L;
      DP[L][R][3] = r;
      DP[L][R][4] = l;
      DP[L][R][5] = R;
    }
  }

  DP[L][R][0] = ret;
}

void P(int L, int R) {
  if(R-L == 1) {
    cout << L << " " << R << "\n";
    return;
  }

  if(DP[L][R][2] == L && DP[L][R][3] == R) {
    cout << DP[L][R][2] << " " << DP[L][R][3] << "\n";
    P(DP[L][R][4], DP[L][R][5]);
  } else {
    P(DP[L][R][2], DP[L][R][3]);
    P(DP[L][R][4], DP[L][R][5]);
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> str;
  for(int i = 1; i <= N; i++) {
    if(str[i-1] == '0') {
      sum[0][i] = sum[0][i-1]+1;
      sum[1][i] = sum[1][i-1];
    } else {
      sum[0][i] = sum[0][i-1];
      sum[1][i] = sum[1][i-1]+1;
    }
  }

  F(1, N);

  cout << DP[1][N][0] << "\n";
  P(1, N);

  return 0;
}