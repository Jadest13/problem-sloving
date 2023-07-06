#include <iostream>
#include <cmath>

using namespace std;

int N, f[41];

int F1(int n) {
  if(n==1 || n==2) {
    return 1;
  } else {
    return F1(n-1) + F1(n-2);
  }
}

int F2(int n) {
  f[1] = 1;
  f[2] = 1;
  for(int i = 3; i <= n; i++) {
    f[i] = f[i-1] + f[i-2];
  }
  return n-2<1?0:n-2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;

  cout << F1(N) << " " << F2(N);

  return 0;
}