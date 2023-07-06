#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 65536

using namespace std;
using LL = long long;

int N, K;
int X;
int A[250001];
int SEG[MAX*4];
LL R;

int segUpdate(int n, int s, int e, int i, int a) {
  if(i < s || e < i) return SEG[n];
  if(s==e) return SEG[n] += a;

  int m = (s+e)>>1;
  return SEG[n] = segUpdate(n*2, s, m, i, a) + segUpdate(n*2+1, m+1, e, i, a);
}

int segQuery(int n, int s, int e, int a) {
  if(s==e) return s;

  int m = (s+e)>>1;
  if(SEG[n*2] >= a) {
    return segQuery(n*2, s, m, a);
  } else {
    return segQuery(n*2+1, m+1, e, a-SEG[n*2]); 
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
    segUpdate(1, 0, MAX-1, A[i], 1);
    if(i >= K) {
      R += segQuery(1, 0, MAX-1, ((K+1)/2));
      segUpdate(1, 0, MAX-1, A[i-K+1], -1);
    }
  }
  
  cout << R;

  return 0;
}