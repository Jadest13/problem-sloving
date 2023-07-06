#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 250001

using namespace std;
using LL = long long;

int N, X;
int A[MAX];
LL tmp;
LL R1, R2;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N >> X;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for(int i = 0; i < X-1; i++) {
    tmp += A[i];
  }

  int l = 0, r = l+X-1;
  while(r < N) {
    tmp += A[r];
    
    if(tmp > R1) {
      R1 = tmp;
      R2 = 1;
    } else if(R1 == tmp) {
      R2++;
    }

    tmp -= A[l];
    l++;
    r++;
  }

  if(R1) cout << R1 << "\n" << R2;
  else cout << "SAD";
  
  return 0;
}