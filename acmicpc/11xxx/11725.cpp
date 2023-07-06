#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int a, b;
int V[100001], R[100001];
vector<int> E[100001];

void bfs() {
  queue<int> Q;
  V[1] = 1;
  Q.push(1);

  while(!Q.empty()) {
    int p = Q.front();
    Q.pop();

    for(auto a : E[p]) {
      if(!V[a]) {
        R[a] = p;
        V[a] = 1;
        Q.push(a);
      }
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i < N; i++) {
    cin >> a >> b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  bfs();

  for(int i = 2; i <= N; i++) {
    cout << R[i] << "\n";
  }

  return 0;
}