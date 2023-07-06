#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T;
int n, m;
int u, v;
int R;
int V[501];
vector<int> E[501];

int F(int n, int i) {
  bool tree = true;
  
  V[n] = 1;
  for(auto a : E[n]) {
    if(!V[a]) {
      if(!F(a, n)) tree = false;
    } else if(a != i) {
      return 0;
    }
  }
  return tree;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while(++T) {
    R = 0;

    cin >> n >> m;
    if(!n && !m) break;

    for(int i = 0; i <= n; i++) {
      V[i] = 0;
      E[i].clear();
    }

    for(int i = 1; i <= m; i++) {
      cin >> u >> v;
      E[u].push_back(v);
      E[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
      if(V[i]) continue;
      
      R += (F(i, -1)?1:0);
    }

    if(!R) cout << "Case " << T << ": No trees.\n";
    else if(R == 1) cout << "Case " << T << ": There is one tree.\n";
    else cout << "Case " << T << ": A forest of " << R << " trees.\n";
  }

  return 0;
}