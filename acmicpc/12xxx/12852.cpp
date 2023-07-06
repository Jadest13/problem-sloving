#include <iostream>
#include <algorithm>

using namespace std;

int N;
int DP[1000001];
int B[1000001];

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  DP[1] = 0;
  for(int i = 2; i <= N; i++) {
    DP[i] = DP[i-1] + 1;
    B[i] = i-1;

    if(i%3 == 0 && DP[i] > DP[i/3]+1) {
      DP[i] = DP[i/3] + 1;
      B[i] = i/3;
    }

    if(i%2 == 0 && DP[i] > DP[i/2]+1) {
      DP[i] = DP[i/2] + 1;
      B[i] = i/2;
    }
  }

  cout << DP[N] << "\n";

  while(N) {
    cout << N << " ";
    N = B[N];
  }

  return 0;
}