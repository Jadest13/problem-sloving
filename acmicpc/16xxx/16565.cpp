#include <iostream>
#include <algorithm>

#define MOD 10007

using namespace std;

int N;
int nCk[53][53];

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int n = 0; n <= 52; n++) {
    nCk[n][0] = 1;
    nCk[n][n] = 1;
    for(int k = 1; k < n; k++) {
      nCk[n][k] = nCk[n-1][k-1] + nCk[n-1][k];
      nCk[n][k] %= MOD;
      nCk[n][n-k] = nCk[n][k];
    }
  }
}