#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

int N, K;
int V[100001];
int P[100001];
queue<int> Q;
stack<int> S;

int F() {
  V[N] = 1;
  Q.push(N);

  while(!Q.empty()) {
    int p = Q.front();

    Q.pop();

    if(p == K) {
      break;
    }

    if(p > 0 && !V[p-1]) {
      V[p-1] = V[p]+1;
      P[p-1] = p;
      Q.push(p-1);
    }

    if(p < 100000 && !V[p+1]) {
      V[p+1] = V[p]+1;
      P[p+1] = p;
      Q.push(p+1);
    }

    if(p*2 <= 100000 && !V[p*2]) {
      V[p*2] = V[p]+1;
      P[p*2] = p;
      Q.push(p*2);
    }
  }

  return V[K];
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  memset(P, -1, sizeof(P));

  cin >> N >> K;
  cout << F()-1 << "\n";

  for(int i = K; P[K] >= 0; K = P[K]) {
    S.push(K);
  }
  S.push(N);

  for(int i = S.size(); i > 0; i--) {
    cout << S.top() << " ";
    S.pop();
  }

  return 0;
}