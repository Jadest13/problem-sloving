#include <iostream>
#include <algorithm>

using namespace std;

int V, E;
int A, B, C;
int P[10001];
vector<pair<int, pair<int, int>>> W;
int R;

int find_node(int x) {
  if(x == P[x]) return x;
  else return P[x] = find_node(P[x]);
}

void union_node(int u, int v) {
  u = find_node(u);
  v = find_node(v);
  if(u != v) P[v] = u;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> V >> E;

  for(int i = 1; i <= V; i++) {
    P[i] = i;
  }

  for(int i = 1; i <= E; i++) {
    cin >> A >> B >> C;
    W.push_back({C, {A, B}});
  }
  sort(W.begin(), W.end());

  for(auto a : W) {
    int u = find_node(a.second.first);
    int v = find_node(a.second.second);

    if(u==v) continue;
    
    R += a.first;
    union_node(u, v);
  }

  cout << R;

  return 0;
}