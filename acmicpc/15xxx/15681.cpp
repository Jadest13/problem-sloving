#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX INT32_MAX

int n, r, q;
int U, V;
vector<int> E[100001];
vector<int> R[100001];
int visit[100001];
int res[100001];

int DFS(int p) {
  int ret = 0;
  for(auto a : R[p]) {
    ret += DFS(a);
  }
  return res[p] = ret + 1;
}

void BFS() {
  queue<int> Q;
  visit[r] = 1;
  Q.push(r);

  while(!Q.empty()) {
    int p = Q.front();
    Q.pop();

    for(auto a : E[p]) {
      if(!visit[a]) {
        visit[a] = 1;
        Q.push(a);
        R[p].push_back(a);
      }
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> r >> q;
  for(int i = 1; i < n; i++) {
    cin >> U >> V;
    E[U].push_back(V);
    E[V].push_back(U);
  }

  BFS();
  DFS(r);

  for(int i = 1; i <= q; i++) {
    cin >> U;
    cout << res[U] << "\n";
  }

  return 0;
}