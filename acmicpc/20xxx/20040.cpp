#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N, M;
int a, b;
int p[500001];
int R;

int find_node(int x) {
  if(x == p[x]) return x;
  else return p[x] = find_node(p[x]);
}

int union_find(int u, int v) {
  u = find_node(u);
  v = find_node(v);
  if(u == v) return 1;
  else {
    p[v] = u;
    return 0;
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for(int i = 0; i < N; i++) {
    p[i] = i;
  }

  for(int i = 1; i <= M; i++) {
    cin >> a >> b;
    if(union_find(a, b)) {
      R = i;
      break;
    }
  }

  cout << R;

  return 0;
}