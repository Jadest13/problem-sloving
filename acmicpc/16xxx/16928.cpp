#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int u, v;
int E[101], V[101];
queue<int> Q;

void F() {
  Q.push(1);
  V[1] = 0;
  
  while(!Q.empty()) {
    int p = Q.front();
    Q.pop();

    if(p == 100) {
      break;
    }

    for(int i = 1; i <= 6; i++) {
      int n = p+i;

      if(n > 100) {
        continue;
      }

      if(V[n] == -1) {
        n = E[n];
      }

      if(V[n] > V[p] + 1) {
        V[n] = V[p] + 1;
        Q.push(n);
      }
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  memset(V, 10000, sizeof(V));

  cin >> N >> M;
  for(int i = 0; i < N + M; i++) {
    cin >> u >> v;
    V[u] = -1;
    E[u] = v;
  }

  F();

  cout << V[100];

  return 0;
}