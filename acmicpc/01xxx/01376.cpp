#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N, M;
int u, v;
int visit[100001];
vector<int> E[100001];

void MFS(int n) {
  visit[n] = 1;
  cout << n << " ";
  
  for(auto a : E[n]) {
    int idx = lower_bound(E[a].begin(), E[a].end(), n) - E[a].begin();
    E[a].erase(E[a].begin() + idx);
  }
  
  while(!E[n].empty()) {
    int sz = E[n].size();
    int idx;
    if(sz&1) {
      idx = (sz-1)>>1;
    } else {
      idx = 0;
    }

    int next = E[n][idx];

    if(!visit[next]) {
      MFS(next);
    }

    for(int i = 0; i < E[n].size(); i++) {
      if(visit[E[n][i]]) {
        E[n].erase(E[n].begin()+i);
        i--;
      }
    }
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;
  for(int i = 1; i <= M; i++) {
    cin >> u >> v;
    if(u==v) continue;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  for(int i = 1; i <= N; i++) {
    sort(E[i].begin(), E[i].end());
    E[i].erase(unique(E[i].begin(), E[i].end()), E[i].end());
  }

  MFS(1);

  return 0;
}