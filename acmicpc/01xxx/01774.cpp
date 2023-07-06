#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX INT32_MAX

int N, M;
int x, y;
int u, v;
pair<int, int> pos[1001];
vector<pair<double, pair<int, int>>> E;
int P[1001];
double R;

int find_node(int x) {
  if(x == P[x]) return x;
  else return P[x] = find_node(P[x]);
}

void union_node(int u, int v) {
  u = find_node(u);
  v = find_node(v);
  if(u != v) P[v] = u;
}

double calc(pair<int, int> a, pair<int, int> b) {
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for(int i = 1; i <= N; i++) {
    P[i] = i;
  }

  for(int i = 1; i <= N; i++) {
    cin >> x >> y;
    pos[i] = {x, y};
  }

  for(int i = 1; i <= M; i++) {
    cin >> u >> v;

    E.push_back({calc(pos[u], pos[v]), {u, v}});
  }
  
  sort(E.begin(), E.end());

  for(auto a : E) {
    int u = find_node(a.second.first);
    int v = find_node(a.second.second);

    union_node(u, v);
  }

  E.clear();

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      E.push_back({calc(pos[i], pos[j]), {i, j}});
    }
  }

  sort(E.begin(), E.end());

  for(auto a : E) {
    int u = find_node(a.second.first);
    int v = find_node(a.second.second);

    if(u==v) continue;

    R += a.first;
    union_node(u, v);
  }

  cout << fixed;
  cout.precision(2);
  cout << R;

  return 0;
}