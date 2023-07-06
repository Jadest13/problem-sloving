#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, a;
vector<int> A;
int S;

int max(int a, int b) {
  return ((a>b)?a:b);
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> a;
    A.push_back(a);
  }
  sort(A.begin(), A.end());

  for(int i = 0; i < A.size(); i++) {
    S = max(S, A[i]*(A.size()-i));
  }

  cout << S;

  return 0;
}