#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long N, sum;
long long L[100001];
long long P[100001];
long long G = 1e9;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i < N; i++) {
    cin >> L[i];
  }
  for(int i = 1; i <= N; i++) {
    cin >> P[i];
  }

  for(int i = 1; i <= N; i++) {
    if(P[i] < G) {
      G = P[i];
    }
    sum += G * L[i];
  }

  cout << sum;

  return 0;
}