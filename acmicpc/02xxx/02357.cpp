#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
long long a, b;
long long A[100001];
long long *MAX, *MIN;

long long init_max(int n, int s, int e) {
  if(s == e) return MAX[n] = A[s];
  long long a = init_max(n*2, s, (s+e)/2);
  long long b = init_max(n*2+1, (s+e)/2 + 1, e);
  return MAX[n] = ((a>b)?a:b);
}

long long init_min(int n, int s, int e) {
  if(s == e) return MIN[n] = A[s];
  long long a = init_min(n*2, s, (s+e)/2);
  long long b = init_min(n*2+1, (s+e)/2 + 1, e);
  return MIN[n] = ((a<b)?a:b);
}

long long get_max(int n, int s, int e, int l, int r) {
  if(l > e || r < s) return 0;
  if(l <= s && e <= r) return MAX[n];
  long long a = get_max(n*2, s, (s+e)/2, l, r);
  long long b = get_max(n*2 + 1, (s+e)/2+1, e, l, r);
  return ((a>b)?a:b);
}

long long get_min(int n, int s, int e, int l, int r) {
  if(l > e || r < s) return 1000000001;
  if(l <= s && e <= r) return MIN[n];
  long long a = get_min(n*2, s, (s+e)/2, l, r);
  long long b = get_min(n*2 + 1, (s+e)/2+1, e, l, r);
  return ((a<b)?a:b);
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int h = ceil(log2(N));
  MAX = new long long[1<<(h+1)];
  MIN = new long long[1<<(h+1)];

  init_max(1, 0, N-1);
  init_min(1, 0, N-1);

  for(int i = 0; i < M; i++) {
    cin >> a >> b;
    cout << get_min(1, 0, N-1, a-1, b-1) << " ";
    cout << get_max(1, 0, N-1, a-1, b-1) << "\n";
  }

  return 0;
}