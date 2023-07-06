#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int t, a, b;
int p[1000001];

int find_node(int x) {
  if(x == p[x]) return x;
  else return p[x] = find_node(p[x]);
}

void union_find(int u, int v) {
  u = find_node(u);
  v = find_node(v);
  if(u != v) p[v] = u;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i = 0; i <= n; i++) {
    p[i] = i;
  }

  for(int i = 1; i <= m; i++) {
    cin >> t >> a >> b;
    if(!t) {
      union_find(a, b);
    } else {
      cout << ((find_node(a) == find_node(b))?"YES\n":"NO\n");
    }
  }

  return 0;
}