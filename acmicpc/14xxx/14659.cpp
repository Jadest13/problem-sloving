#include <iostream>
#include <algorithm>

using namespace std;

int N, A[30001];
int R;

int F(int n) {
  int a = 0;
  for(int i = n+1; i <= N; i++) {
    if(A[i] > A[n]) break;
    a++;
  }
  return a;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  for(int i = 1; i <= N; i++) {
    int a = 0;
    for(int j = i+1; j <= N; j++) {
      if(A[j] > A[i]) break;
      a++;
    }
    R = max(a, R);
  }

  cout << R;

  return 0;
}