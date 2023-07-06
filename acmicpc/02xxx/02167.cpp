#include <iostream>
#include <algorithm>

#define MAX 301

using namespace std;

int N, M;
int K;
int x1, y1, x2, y2;
int ARR[MAX][MAX];
int SUM[MAX][MAX];

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> ARR[i][j];
      SUM[i][j] = SUM[i-1][j] + SUM[i][j-1] - SUM[i-1][j-1] + ARR[i][j];
    }
  }
  cin >> K;
  for(int i = 1; i <= K; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << SUM[x2][y2] - SUM[x1-1][y2] - SUM[x2][y1-1] + SUM[x1-1][y1-1] << "\n";
  }

  return 0;
}