#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX INT32_MAX

int n;
double x, y;
int P[101];
vector<pair<double, double>> V;
vector<tuple<double, int, int>> D;
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

double calc(pair<double, double> a, pair<double, double> b) {
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for(int i = 1; i <= n; i++) {
    P[i] = i;
  }

  for(int i = 1; i <= n; i++) {
    cin >> x >> y;
    V.push_back({x, y});
  }

  for(int i = 0; i < V.size(); i++) {
    for(int j = 0; j < V.size(); j++) {
      D.push_back({calc(V[i], V[j]), i, j});
    }
  }

  sort(D.begin(), D.end());

  for(int i = 0; i < D.size(); i++) {
    int u = find_node(get<1>(D[i]));
    int v = find_node(get<2>(D[i]));

    if(u == v) continue; 

    R += get<0>(D[i]);
    union_node(u, v);
  }

  cout.precision(3);
  cout << R;

  return 0;
}