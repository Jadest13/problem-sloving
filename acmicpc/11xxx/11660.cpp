#include <iostream>

using namespace std;

int N, M, a;
int x, y, x2, y2;
long P[1025][1025];

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> a;
      P[i][j] = P[i-1][j] + P[i][j-1] - P[i-1][j-1] + a;
    }
  }

  for(int i = 0; i < M; i++) {
    cin >> x >> y >> x2 >> y2;
    cout << P[x2][y2] - P[x2][y-1] - P[x-1][y2] + P[x-1][y-1] << "\n";
  }

  return 0;
}