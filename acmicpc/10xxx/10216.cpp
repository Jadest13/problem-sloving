#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef struct {
  int x, y, r;
} Top;

int T;
int N;
int x, y, r;
vector<Top> V;
int P[3001];
map<int, int> R;

int find_node(int x) {
  if(x == P[x]) return x;
  else return P[x] = find_node(P[x]);
}

void union_find(int u, int v) {
  u = find_node(u);
  v = find_node(v);
  if(u != v) P[v] = u;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while(T--) {
    V.clear();
    R.clear();

    cin >> N;

    for(int i = 1; i <= N; i++) {
      P[i] = i;
    }

    for(int i = 1; i <= N; i++) {
      cin >> x >> y >> r;
      for(int j = 1; j <= V.size(); j++) {
        if(P[i] == P[j]) continue;
        if(r + V[j-1].r < sqrt(pow(x-V[j-1].x, 2) + pow(y-V[j-1].y,2))) continue;
        union_find(j, i);
      }
      V.push_back({x, y, r});
    }

    for(int i = 1; i <= N; i++) {
      R[find_node(i)]++;
    }
    cout << R.size() << "\n";
  }

  return 0;
}