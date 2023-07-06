#include <iostream>

using namespace std;

int N, M, a;
long long P[1001], sum;
long long R;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for(int i = 0; i < N; i++) {
    cin >> a;
    sum += a;
    P[sum%M]++;
  }

  for(int i = 0; i <= M; i++) {
    R += P[i] * (P[i]-1) / 2;
  }
  R += P[0];

  cout << R;

  return 0;
}