#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
int a, A[100001];
int V1[100001], V2[100001];
queue<int> Q1, Q2;

void F2(int n);

void F1(int n) {
  Q2.pop();
  for(int i = K; i > 0; i--) {
    int p = n+i;
    if(p <= 100000 && !A[p] && !V1[p]) {
      Q1.push(p);
      F2(p);
    }
  }
}

void F2(int n) {
  Q1.pop();
  for(int i = K; i > 0; i--) {
    int p = n+i;
    if(p <= 100000 && !A[p] && !V2[p]) {
      Q2.push(p);
      F1(p);
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  while(!cin.eof()) {
    cin >> a;
    A[a] = 1;
  }

  Q2.push(0);
  V1[0] = 1;
  F1(0);

  if(Q1.empty()) {
    cout << 0;
  } else {
    cout << 1;
  }

  return 0;
}