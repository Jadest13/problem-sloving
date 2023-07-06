#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

int N;
vector<pair<PLL, PLL>> L;

int p[3001];
int s[3001];
int v[3001];
int cnt, R;;

int find_node(int x) {
  if(x == p[x]) return x;
  else return p[x] = find_node(p[x]);
}

void union_node(int u, int v) {
  u = find_node(u);
  v = find_node(v);
  if(u != v) {
    if(s[u] < s[v]) swap(u, v);
    p[v] = u;
    s[u] += s[v];
    s[v] = 0;
  }
}

int ccw(pair<LL, LL> p1, pair<LL, LL> p2, pair<LL, LL> p3) {
  LL tmp = (p1.first * p2.second) + (p2.first * p3.second) + (p3.first * p1.second);
  tmp -= (p1.first * p3.second) + (p2.first * p1.second) + (p3.first * p2.second);

  if(tmp > 0) return 1;
  else if(tmp < 0) return -1;
  else return 0;
}

int check(PLL A, PLL B, PLL C, PLL D) {

  int ans1 = ccw(A, B, C) * ccw(A, B, D);
  int ans2 = ccw(C, D, A) * ccw(C, D, B);

  if(!ans1 && !ans2) {
    if(A > B) swap(A, B);
    if(C > D) swap(C, D);
    if(A <= D && B >= C) {
      return 1;
    }
    return 0;
  } else if(ans1 <= 0 && ans2 <= 0) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for(int i = 0; i < N; i++) {
    p[i] = i;
    s[i] = 1;
  }

  for(int i = 0; i < N; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    L.push_back({{x1, y1}, {x2, y2}});
  }

  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      if(check(L[i].first, L[i].second, L[j].first, L[j].second)) {
        int u = find_node(i);
        int v = find_node(j);

        if(u == v) continue;

        union_node(u, v);
      }
    }
  }

  for(int i = 0; i < N; i++) {
    int u = find_node(i);
    
    if(!v[u]) {
      v[u] = 1;
      cnt++;
      R = max(R, s[u]);
    }
  }

  cout << cnt << "\n" << R;

  return 0;
}