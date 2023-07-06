#include <iostream>
#include <algorithm>

#define MAX 1001

using namespace std;

int N;
int A[MAX];
int DP[MAX];

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  for(int i = 1; i <= N; i++) {
    DP[i] = A[i];
    for(int j = 1; j <= i/2; j++) {
      DP[i] = min(DP[i], DP[j] + DP[i-j]);
    }
  }

  cout << DP[N];

  return 0;
}