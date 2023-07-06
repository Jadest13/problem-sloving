#include <iostream>
#include <algorithm>

using namespace std;

int n, q;
int t;
int s, a, b, c, d;
int B[1001];
long A[1001];

int main(void) {

  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> B[i];
    A[i] = A[i-1] + B[i];
  }
  for(int i = 1; i <= q; i++) {
    cin >> s;
    if(s == 1) {
      cin >> a >> b;
      cout << A[b] - A[a-1] << "\n";
      int tmp = B[a];
      B[a] = B[b];
      B[b] = tmp;
      for(int i = a; i <= n; i++) {
        A[i] = A[i-1] + B[i];
      }
    } else {
      cin >> a >> b >> c >> d;
      cout << (A[b] - A[a-1]) - (A[d]-A[c-1]) << "\n";
    }
  }


  return 0;
}