#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int A[1001], DP[1001];
int cnt;
vector<int> V, R;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  for(int i = 1; i <= N; i++) {
    if(V.empty() || V.back() < A[i]) {
      V.push_back(A[i]);
      DP[i] = ++cnt;
    } else {
      int p = lower_bound(V.begin(), V.end(), A[i]) - V.begin();
      V[p] = A[i];
      DP[i] = p+1;
    }
  }

  for(int i = N; i >= 1; i--) {
    if(DP[i] == cnt) {
      R.push_back(A[i]);
      cnt--;
    }
  }

  reverse(R.begin(), R.end());

  cout << R.size() << "\n";
  for(auto a : R) {
    cout << a << " ";
  }

  return 0;
}