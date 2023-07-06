#include <bits/stdc++.h>

#define MAX 100001

using namespace std;

int T;
int N, M;
vector<int> E[MAX];
vector<int> stk;

int SCC_cnt;
int SCC_id[MAX];
int SCC_indegree[MAX];
int discovered[MAX];
int V_cnt;
int ans;

int SCC(int n) {
  int ret = discovered[n] = V_cnt++;

  stk.push_back(n);

  for(auto a : E[n]) {
    if(discovered[a] == -1) {
      ret = min(ret, SCC(a));
    } else if(SCC_id[a] == -1) {
      ret = min(ret, discovered[a]);
    }
  }

  if(ret == discovered[n]) {
    while(1) {
      int tmp = stk.back();
      stk.pop_back();
      SCC_id[tmp] = SCC_cnt;
      if(tmp == n) break;
    }
    SCC_cnt++;
  }

  return ret;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while(T--) {
    ans = 0;
    V_cnt = 0;
    SCC_cnt = 0;
    memset(discovered, -1, sizeof(discovered));
    memset(SCC_id, -1, sizeof(SCC_id));
    memset(SCC_indegree, 0, sizeof(SCC_indegree));
    for(int i = 0; i < MAX; i++) {
      E[i].clear();
    }

    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
      int x, y;
      cin >> x >> y;
      E[x].push_back(y);
    }

    for(int i = 1; i <= N; i++) {
      if(discovered[i] != -1) continue;
      SCC(i);
    }

    for(int i = 1; i<= N; i++) {
      for(auto a : E[i]) {
        if(SCC_id[a] == SCC_id[i]) continue;
        SCC_indegree[SCC_id[a]]++;
      }
    }

    for(int i = 0; i < SCC_cnt; i++) {
      if(!SCC_indegree[i]) ans++;
    }

    cout << ans << "\n";
  }

  return 0;
}