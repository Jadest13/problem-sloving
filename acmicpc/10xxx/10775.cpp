#include <iostream>
#include <algorithm>

using namespace std;

int G, P;
int g[100001];
int p[100001];
int R;

int findP(int x) {
  if(p[x] == x) return x;
  else return p[x] = findP(p[x]);
}

void unionP(int u, int v) {
  u = findP(u);
  v = findP(v);
  p[u] = v;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> G >> P;
  for(int i = 1; i <= G; i++) p[i] = i;
  for(int i = 1; i <= P; i++) {
    cin >> g[i];
  }

  for(int i = 1; i <= P; i++) {
    if(findP(g[i]) == 0) break;
    else {
      R++;
      unionP(findP(g[i]), findP(g[i])-1);
    }
  }

  cout << R;

  return 0;
}