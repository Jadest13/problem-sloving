#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int V[100001];
int m;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
int ret = 1e9;

int F() {
  PQ.push({0, N});
  V[N] = 1;
  
  while(!PQ.empty()) {
    int t = PQ.top().first;
    int p = PQ.top().second;

    PQ.pop();

    if(p == K) {
      return t;
    }

    if(p*2 <= 100000 && !V[p*2]) {
      PQ.push({t, p*2});
      V[p*2] = 1;
    }

    if(p > 0 && !V[p-1]) {
      PQ.push({t+1, p-1});
      V[p-1] = 1;
    }

    if(p < 100000 && !V[p+1]) {
      PQ.push({t+1, p+1});
      V[p+1] = 1;
    }
  }
  return 0;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  cout << F();

  return 0;
}