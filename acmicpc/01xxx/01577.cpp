#include <bits/stdc++.h>

#define MAX 101

using namespace std;
using LL = long long;
using PII = pair<int, int>;

int N, M;
int K;
int a, b, c, d;
int A[MAX][MAX];
vector<PII> E[MAX][MAX];
LL DP[MAX][MAX];

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  cin >> K;
  for(int i = 1; i <= K; i++) {
    cin >> a >> b >> c >> d;
    if(a > c) swap(a, c);
    if(b > d) swap(b, d);
    E[a][b].push_back({c, d});
  }

  DP[0][0] = 1;
  for(int i = 0; i <= M; i++) {
    if(i != 0) {
      if(find(E[0][i-1].begin(), E[0][i-1].end(), make_pair(0, i)) == E[0][i-1].end()) {
        DP[i][0] = DP[i-1][0];
      }
    }
    for(int j = 1; j <= N; j++) {
      if(i == 0) {
        if(find(E[j-1][i].begin(), E[j-1][i].end(), make_pair(j, i)) == E[j-1][i].end()) {
          DP[i][j] = DP[i][j-1];
        }
      } else {
        if(find(E[j-1][i].begin(), E[j-1][i].end(), make_pair(j, i)) == E[j-1][i].end()) {
          DP[i][j] += DP[i][j-1];
        }
        if(find(E[j][i-1].begin(), E[j][i-1].end(), make_pair(j, i)) == E[j][i-1].end()) {
          DP[i][j] += DP[i-1][j];
        }
      }
    }
  }

  cout << DP[M][N];

  return 0;
}