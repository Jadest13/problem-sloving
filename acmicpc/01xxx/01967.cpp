#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int u, v, w;
vector<pair<int, int>> E[10001];
int V[10001];
int Md, Mn;

void F(int n, int d) {
  if(V[n]) return;
  
  if(Md < d) {
    Md = d;
    Mn = n;
  }

  V[n] = 1;

  for(auto a : E[n]) {
    F(a.first, a.second+d);
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for(int i = 1; i < N; i++) {
    cin >> u >> v >> w;
    E[u].push_back({v, w});
    E[v].push_back({u, w});
  }

  F(1, 0);
  memset(V, 0, sizeof(V));
  F(Mn, 0);
  cout << Md;

  return 0;
}