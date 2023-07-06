#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

#define MAX INT32_MAX

using namespace std;

int N;
int x, y, z;
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;
vector<tuple<int, int, int>> D;
int P[100001];
int R;

int find(int u) {
  if(P[u] == u) return u;
  else return P[u] = find(P[u]);
}

int F(int u, int v) {
  u = find(u);
  v = find(v);

  if(u == v) return 0;
  else {
    P[u] = v;
    return 1;
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for(int i = 0; i < N; i++) {
    P[i] = i;
  }

  for(int i = 0; i < N; i++) {
    cin >> x >> y >> z;
    X.push_back({x, i});
    Y.push_back({y, i});
    Z.push_back({z, i});
  }

  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  sort(Z.begin(), Z.end());

  for(int i = 1; i < N; i++) {
    D.push_back({X[i].first-X[i-1].first, X[i-1].second, X[i].second});
    D.push_back({Y[i].first-Y[i-1].first, Y[i-1].second, Y[i].second});
    D.push_back({Z[i].first-Z[i-1].first, Z[i-1].second, Z[i].second});
  }

  sort(D.begin(), D.end());
  
  for(auto a : D) {
    int d = get<0>(a);
    int u = get<1>(a);
    int v = get<2>(a);

    if(F(u, v)) R += d;
  }

  cout << R;

  return 0;
}