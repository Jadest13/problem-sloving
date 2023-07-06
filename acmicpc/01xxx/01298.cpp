#include <bits/stdc++.h>

#define MAX 101

using namespace std;

int N, M;
int Match[MAX];
vector<int> V[MAX];
int visited[MAX];
int R;

int PM(int n) {
  if(visited[n]) return 0;
  visited[n] = 1;

  for(auto a : V[n]) {
    if(!Match[a]) {
      Match[a] = n;
      return 1;
    }
  }

  for(auto a : V[n]) {
    if(PM(Match[a])) {
      Match[a] = n;
      return 1;
    }
  }

  return 0;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= M; i++) {
    int a, b;
    cin >> a >> b;
    V[a].push_back(b);
  }

  for(int i = 1; i <= N; i++) {
    fill(visited, visited+MAX, 0);
    if(PM(i)) R++;
  }

  cout << R;

  return 0;
}