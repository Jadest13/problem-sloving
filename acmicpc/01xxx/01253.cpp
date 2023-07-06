#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[2001];
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A+N);
  for(int i = 0; i < N; i++) {
    int l = 0, r = N-1;
    while(l < r) {
      if(A[l]+A[r] == A[i]) {
        if(l == i) l++;
        else if(r == i) r--;
        else {
          R++;
          break;
        }
      }
      else if(A[l]+A[r] > A[i]) r--;
      else l++;
    }
  }

  cout << R;

  return 0;
}