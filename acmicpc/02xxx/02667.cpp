#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
string S;
int A[27][27], V[27][27];
vector<int> E[101], R;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int cnt;

int F(int x, int y) {
  int res = 1;

  V[x][y] = 1;

  for(int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(A[nx][ny] && !V[nx][ny]) {
      res += F(nx, ny);
    }
  }

  return res;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> S;
    for(int j = 1; j <= N; j++) {
      A[i][j] = S[j-1] - '0';
    }
  }

  for(int i = 1 ; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      if(A[i][j] && !V[i][j]) {
        R.push_back(F(i, j));
        cnt++;
      }
    }
  }
  sort(R.begin(), R.end());
  cout << cnt << "\n";
  for(int i = 0; i < R.size(); i++) {
    cout << R[i] << "\n";
  }

  return 0;
}