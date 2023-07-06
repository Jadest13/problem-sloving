#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, R;
int u, v;
int V[100001];
int cnt = 1;
vector<int> E[100001];

void dfs(int x) {
  V[x] = cnt++;
  for(int i = 0; i < E[x].size(); i++) {
    if(!V[E[x].at(i)]) dfs(E[x].at(i));
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> R;
  for(int i = 0; i < M; i++) {
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  for(int i = 1; i <= N; i++) {
    sort(E[i].rbegin(), E[i].rend());
  }
  
  dfs(R);

  for(int i = 1; i <= N; i++) {
    cout << V[i] << "\n";
  }

  return 0;
}