#include <bits/stdc++.h>

#define MAX 1001

using namespace std;

int N, M;
vector<int> E[MAX];
int Match[MAX];
int Visit[MAX];
int ans;

int PM(int n) {
  if(Visit[n]) return 0;
  Visit[n] = 1;

  for(auto a : E[n]) {
    if(Match[a]) continue;
    Match[a] = n;
    return 1;
  }

  for(auto a : E[n]) {
    if(!PM(Match[a])) continue;
    Match[a] = n;
    return 1;
  }

  return 0;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    int n;
    cin >> n;
    for(int j = 1; j <= n; j++) {
      int v;
      cin >> v;
      E[i].push_back(v);
    }
  }

  for(int i = 1; i <= N; i++) {
    fill(Visit+1, Visit+N+1, 0);
    if(PM(i)) ans++;
  }

  cout << ans;

  return 0;
}