#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 1e9
#define MAX 2001

using namespace std;
using PII = pair<int, int>;

int T;
int n, m, t;
int s, g, h;
int a, b, d;
int x;
vector<PII> E[MAX];
int D[MAX];
vector<int> R;

void Dijk(int s) {
  priority_queue<PII, vector<PII>, greater<PII>> PQ;
  for(int i = 1; i <= n; i++) D[i] = INF;

  D[s] = 0;
  PQ.push({D[s], s});

  while(!PQ.empty()) {
    int pc = PQ.top().first;
    int pp = PQ.top().second;
    PQ.pop();

    for(auto a : E[pp]) {
      int nc = a.second;
      int np = a.first;

      if(pc + nc < D[np]) {
        D[np] = pc + nc;
        PQ.push({D[np], np});
      }
    }
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while(T--) {
    int gh;
    R.clear();
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++) {
      E[i].clear();
    }
    cin >> s >> g >> h;
    for(int i = 1; i <= m; i++) {
      cin >> a >> b >> d;
      E[a].emplace_back(b, d);
      E[b].emplace_back(a, d);
      if((a==g && b==h)||(a==h && b==g)) gh = d;
    }

    for(int i = 1; i <= t; i++) {
      cin >> x;
      Dijk(s);
      int R1 = D[x];
      int R2 = D[g];
      int R3 = D[h];
      Dijk(g);
      R3 += D[x]+gh;
      Dijk(h);
      R2 += D[x]+gh;

      if(min(R2, R3) == R1) R.push_back(x);
    }
    sort(R.begin(), R.end());
    for(auto a : R) {
      cout << a << " ";
    }
    cout << "\n";
  }
  
  return 0;
}