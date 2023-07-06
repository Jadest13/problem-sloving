#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, a;
vector<int> A, B;
int S;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> a;
    A.push_back(a);
  }
  for(int i = 1; i <= N; i++) {
    cin >> a;
    B.push_back(a);
  }
  sort(A.begin(), A.end());
  sort(B.rbegin(), B.rend());

  for(int i = 0; i < N; i++) {
    S += A[i] * B[i];
  }

  cout << S;

  return 0;
}