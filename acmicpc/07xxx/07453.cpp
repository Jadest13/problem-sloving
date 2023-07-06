#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 4001

using namespace std;
using LL = long long;

int N;
LL A[MAX], B[MAX], C[MAX], D[MAX];
vector<LL> V1, V2;
LL R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      V1.push_back(A[i]+B[j]);
      V2.push_back(C[i]+D[j]);
    }
  }
  sort(V1.begin(), V1.end());
  sort(V2.begin(), V2.end());

  int l = 0;
  int r = N*N-1;
  LL a, b;
  while(l < N*N && 0 <= r) {
    if(V1[l] + V2[r] == 0) {
      a = 1;
      b = 1;
      while(l+1 < N*N && V1[l+1] == V1[l]) {
        l++;
        a++;
      }
      while(r-1 >= 0 && V2[r-1] == V2[r]) {
        r--;
        b++;
      }
      R += a*b;
      l++;
      r--;
    } else if(V1[l] + V2[r] > 0) {
      r--;
    } else {
      l++;
    }
  }

  cout << R;

  return 0;
}