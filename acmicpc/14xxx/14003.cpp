#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int A[1000001], DP[1000001];
vector<int> V, R;

int main(void) {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];

    if(V.size() == 0 || V[V.size()-1] < A[i]) {
      V.push_back(A[i]);
      DP[i] = V.size() - 1;
    } else {
      int L = 0, R = V.size() - 1;
      while(L < R) {
        int M = (L+R)/2;

        if(V[M] >= A[i]) {
          R = M;
        } else {
          L = M + 1;
        }
      }
      V[L] = A[i];
      DP[i] = L;
    }
  }
  
  cout << V.size() << "\n";

  for(int i = N; i > 0; i--) {
    if(DP[i] == V.size()-1) {
      V.pop_back();
      R.push_back(A[i]);
    }
  }
  for(int i = R.size() - 1; i >= 0; i--) {
    cout << R[i] << " ";
  }

  exit(0);
}