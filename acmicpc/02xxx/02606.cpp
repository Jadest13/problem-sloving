#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int u, v;
vector<int> E[101];
int V[101];
int cnt;

void F(int x) {
  V[x] = 1;

  for(auto a : E[x]) {
    if(!V[a]) {
      cnt++;
      F(a);
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  F(1);

  cout << cnt;

  return 0;
}