#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 5001
#define INF 1e15

using namespace std;
using LL = long long;

int N;
LL A[MAX];
LL R[3];
LL mn = INF;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  sort(A+1, A+N+1);
  for(int i = 1; i <= N; i++) {
    int l = 1, r = N;
    while(l < r) {
      if(l == i) {
        l++;
        continue;
      }
      if(r == i) {
        r--;
        continue;
      }

      if(abs(A[l]+A[r]+A[i]) < mn) {
        mn = abs(A[l]+A[r]+A[i]);
        R[0] = A[l];
        R[1] = A[r];
        R[2] = A[i];
      }

      if(A[l]+A[r]+A[i] < 0) {
        l++;
      } else if(A[l]+A[r]+A[i] > 0) {
        r--;
      } else {
        l++;
        r--;
      }
    }
  }

  sort(R, R+3);
  for(auto a : R) {
    cout << a << " ";
  }

  return 0;
}