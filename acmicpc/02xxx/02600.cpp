#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int B[4];
int k1, k2;
int DP[501][501][2];

int F(int a, int b, int p) {
  if(DP[a][b][p] != -1) return DP[a][b][p];

  for(int i = 1; i <= 3; i++) {
    if(B[i] <= a && !F(a - B[i], b, !p)) return DP[a][b][p] = 1;
  }
  
  for(int i = 1; i <= 3; i++) {
    if(B[i] <= b && !F(a, b - B[i], !p)) return DP[a][b][p] = 1;
  }

  return DP[a][b][p] = false;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  memset(DP, -1, sizeof(DP));

  cin >> B[1] >> B[2] >> B[3];
  for(int i = 0; i < 5; i++) {
    cin >> k1 >> k2;
    if(F(k1, k2, 0)) cout << "A\n";
    else cout << "B\n";
  }

  return 0;
}