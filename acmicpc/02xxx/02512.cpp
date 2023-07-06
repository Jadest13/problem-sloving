#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int A[10001];
int N, M;

int F(int m) {
  for(int i = 1; i <= N; i++) {
    
  }
}

int main(void) {

  int sum = 0;
  int L = 0, R = 0;
  int result;

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
    R = A[i]>R?A[i]:R;
  }
  cin >> M;

  sort(A+1, A+N+1);

  while(L <= R) {
    sum = 0;
    int mid = (L+R)/2;
    for(int i = 1; i <= N; i++) {
      sum += min(A[i], mid);
    }

    if(M >= sum) {
      result = mid;
      L = mid + 1;
    } else {
      R = mid - 1;
    }
  }

  printf("%d", result);

  exit(0);
}