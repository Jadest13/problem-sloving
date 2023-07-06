#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;

int N;
int A[MAX];
int mn = 2000000001;
int R1, R2;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  sort(A+1, A+N+1);
  int l = 1, r = N;
  while(l < r) {
    if(abs(A[l]+A[r]) < mn) {
      mn = abs(A[l]+A[r]);
      R1 = A[l];
      R2 = A[r];
    }
    if(A[l]+A[r] < 0) {
      l++;
    } else {
      r--;
    }
  }

  cout << R1 << " " << R2;

  return 0;
}