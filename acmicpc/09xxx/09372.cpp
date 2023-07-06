#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T;
int N, M;
int a, b;
vector<int> E[1001];
int V[1001];
int R;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while(T--) {
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
      E[i].clear();
      V[i] = 0;
    }

    for(int i = 1; i <= M; i++) {
      cin >> a >> b;
      E[a].push_back(b);
      E[b].push_back(a);
    }
    
    R = 0;
    queue<int> Q;
    Q.push(1);
    V[1] = 1;

    while(!Q.empty()) {
      int p = Q.front();
      Q.pop();
      for(auto a : E[p]) {
        if(!V[a]) {
          R++;
          V[a] = 1;
          Q.push(a);
        }
      }
    }

    cout << R << "\n";
  }

  return 0;
}