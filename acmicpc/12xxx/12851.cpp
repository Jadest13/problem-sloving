#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int V[100001];
int m;
queue<int> Q;
int ret = 1e9;

void F() {
  V[N] = 1;
  Q.push(N);
  
  while(!Q.empty()) {
    int p = Q.front();

    Q.pop();

    if(p == K) {
      ret = V[p];
      m++;
    }

    if(V[p] > ret) {
      continue;
    }

    if(p > 0 && V[p]+1 <= V[p-1]) {
      V[p-1] = V[p]+1;
      Q.push(p-1);
    }

    if(p < 100000 && V[p]+1 <= V[p+1]) {
      V[p+1] = V[p]+1;
      Q.push(p+1);
    }

    if(p*2 <= 100000 && V[p]+1 <= V[p*2]) {
      V[p*2] = V[p]+1;
      Q.push(p*2);
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i = 0; i <= 100000; i++) {
    V[i] = 1e9;
  }

  cin >> N >> K;
  F();
  cout << V[K]-1 << "\n" << m;

  return 0;
}