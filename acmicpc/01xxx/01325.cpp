#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 10001

using namespace std;
using PII = pair<int, int>;

int N, M;
int A, B;
vector<int> E[MAX];
int visit[MAX];
int R[MAX];
int mx;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= M; i++) {
    cin >> A >> B;
    E[B].push_back(A);
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      visit[j] = 0;
    }
    queue<int> Q;
    
    visit[i] = 1;
    Q.push(i);
    while(!Q.empty()) {
      R[i]++;
      int p = Q.front();
      Q.pop();
      for(auto a : E[p]) {
        if(visit[a]) continue;

        visit[a] = 1;
        Q.push(a);
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    mx = max(mx, R[i]);
  }

  for(int i = 1; i <= N; i++) {
    if(R[i] == mx) cout << i << " ";
  }

  return 0;
}