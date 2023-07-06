#include <iostream>

using namespace std;

int N, K;
int n;
long D[100001];
long M = -1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> N >> K;
  for(int i = 1; i <= N; i++) {
    cin >> n;
    D[i] = D[i-1] + n;

    if(i >= K) {
      if(D[i] - D[i-K] > M) {
        M = D[i] - D[i-K];
      }
    }
  }

  cout << M;

  return 0;
}