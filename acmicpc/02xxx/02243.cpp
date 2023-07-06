#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX 1000001

using namespace std;

int N;
int a, b, c;
int A[MAX];
int T[MAX * 4];

int query(int n, int s, int e, int a) {
  if(s == e) return e;

  int m = (s+e)/2;
  if(T[n*2] >= a) return query(n*2, s, m, a);
  else return query(n*2+1, m+1, e, a-T[n*2]);
}

void update(int n, int s, int e, int i, int a) {
  if(i < s || i > e) return;
  if(s == e) {
    T[n] = a;
    return;
  }

  int m = (s+e)/2;
  update(n*2, s, m, i, a);
  update(n*2+1, m+1, e, i, a);
  T[n] = T[n*2] + T[n*2+1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> a >> b;
    if(a == 1) {
      b = query(1, 1, MAX, b);
      cout << b << "\n";
      A[b]--;
    } else {
      cin >> c;
      A[b] += c;
    }
    update(1, 1, MAX, b, A[b]);
  }

  return 0;
}