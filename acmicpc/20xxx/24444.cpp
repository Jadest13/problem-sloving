#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, R;
int u, v;
int V[100001];
int cnt = 1;
vector<int> E[100001];
queue<int> Q;

void bfs() {
  while(!Q.empty()) {
    if(V[Q.front()]) Q.pop();
    else {
      V[Q.front()] = cnt++;

      for(int i = 0; i < E[Q.front()].size(); i++) {
        if(!V[E[Q.front()][i]]) {
          Q.push(E[Q.front()][i]);
        }
      }
      Q.pop();
    }
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
    sort(E[i].begin(), E[i].end());
  }

  Q.push(R);
  bfs();

  for(int i = 1; i <= N; i++) {
    cout << V[i] << "\n";
  }

  return 0;
}