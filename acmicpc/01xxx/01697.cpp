#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int V[100001];
queue<int> Q;

int F() {
  V[N] = 1;
  Q.push(N);

  while(!Q.empty()) {
    int p = Q.front();

    Q.pop();

    if(p == M) {
      break;
    }

    if(p > 0 && !V[p-1]) {
      V[p-1] = V[p]+1;
      Q.push(p-1);
    }

    if(p < 100000 && !V[p+1]) {
      V[p+1] = V[p]+1;
      Q.push(p+1);
    }

    if(p*2 <= 100000 && !V[p*2]) {
      V[p*2] = V[p]+1;
      Q.push(p*2);
    }
  }

  return V[M];
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  cout << F()-1;

  return 0;
}