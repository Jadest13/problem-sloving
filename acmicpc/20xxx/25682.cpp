#include <iostream>

using namespace std;

int A[2001][2001];
int BW[2001][2001][2];
string str;
int N, M, K;
int MAX = 2000*2000+1;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> K;
  for(int i = 1; i <= N; i++) {
    cin >> str;
    for(int j = 1; j <= M; j++) {
      A[i][j] = str[j-1];
      BW[i][j][0] = BW[i-1][j][1] + BW[i][j-1][1] - BW[i-1][j-1][0] + (A[i][j] == 'B'?0:1);
      BW[i][j][1] = BW[i-1][j][0] + BW[i][j-1][0] - BW[i-1][j-1][1] + (A[i][j] == 'W'?0:1);
    }
  }

  for(int i = K; i <= N; i++) {
    for(int j = K; j <= M; j++) {
      MAX = min(BW[i][j][1] - BW[i-K][j][(1+K%2)%2] - BW[i][j-K][(1+K%2)%2] + BW[i-K][j-K][1], MAX);
      MAX = min(BW[i][j][0] - BW[i-K][j][(0+K%2)%2] - BW[i][j-K][(0+K%2)%2] + BW[i-K][j-K][0], MAX);
    }
  }

  cout << MAX;
}