#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

int N;
int X;
int ARR[MAX];
int SEG[MAX*4];

int segInit(int n, int s, int e) {
  if(s==e) return SEG[n] = 1;

  int m = (s+e)>>1;
  return SEG[n] = segInit(n*2, s, m) + segInit(n*2+1, m+1, e);
}

int segUpdate(int n, int s, int e, int i) {
  if(i < s || e < i) return SEG[n];
  if(s==e) return SEG[n] = 0;

  int m = (s+e)>>1;
  return SEG[n] = segUpdate(n*2, s, m, i) + segUpdate(n*2+1, m+1, e, i);
}

int segQuery(int n, int s, int e, int a) {
  if(s==e) return s;

  int m = (s+e)>>1;
  if(SEG[n*2] > a) {
    return segQuery(n*2, s, m, a);
  } else {
    return segQuery(n*2+1, m+1, e, a-SEG[n*2]); 
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  segInit(1, 1, N);
  for(int i = 1; i <= N; i++) {
    cin >> X;
    int idx = segQuery(1, 1, N, X);
    ARR[idx] = i;
    segUpdate(1, 1, N, idx);
  }

  for(int i = 1; i <= N; i++) {
    cout << ARR[i] << "\n";
  }

  return 0;
}