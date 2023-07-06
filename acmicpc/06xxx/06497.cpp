#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;
int X, Y, Z;
vector<pair<int, pair<int, int>>> E;
int P[200001];
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
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(1) {
    for(int i = 0; i < 200001; i++) {
      P[i] = i;
    }
    E.clear();
    R = 0;

    cin >> M >> N;
    if(!M && !N) break;

    for(int i = 0; i < N; i++) {
      cin >> X >> Y >> Z;
      E.push_back({Z, {X, Y}});
    }

    sort(E.begin(), E.end());

    for(auto a : E) {
      int u = find_node(a.second.first);
      int v = find_node(a.second.second);

      if(u == v) {
        R += a.first;
      }

      union_node(u, v);
    }

    cout << R << "\n";
  }

  return 0;
}