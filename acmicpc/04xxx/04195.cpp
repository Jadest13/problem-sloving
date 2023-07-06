#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int T, N;
string S1, S2;
int p[2000001], s[2000001];

int find_node(int x) {
  if(x == p[x]) return x;
  else return p[x] = find_node(p[x]);
}

void union_find(int u, int v) {
  u = find_node(u);
  v = find_node(v);
  if(u != v) {
    if(s[u] < s[v]) swap(u, v);
    p[v] = u;
    s[u] += s[v];
    s[v] = 0;
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;

  while(T--) {
    map<string, int> m;
    int idx = 0;

    cin >> N;

    for(int i = 1; i <= N*2; i++) {
      p[i] = i;
      s[i] = 1;
    }

    for(int i = 1; i <= N; i++) {
      cin >> S1 >> S2;

      if(m.count(S1) == 0) m[S1] = ++idx;
      if(m.count(S2) == 0) m[S2] = ++idx;

      int u = find_node(m[S1]);
      int v = find_node(m[S2]);

      if(u!=v) union_find(u, v);
      
      cout << max(s[u], s[v]) << "\n";
    }
  }

  return 0;
}