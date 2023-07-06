#include <iostream>
#include <algorithm>

#define MAX (200+1)

using namespace std;

int N, M;
int A[MAX][MAX];
int B[1001];
int P[MAX];
int flag;

int find_node(int x) {
  if(P[x] == x) return x;
  else return P[x] = find_node(P[x]);
}

void union_node(int u, int v) {
  if(u > v) swap(u, v);
  u = find_node(u);
  v = find_node(v);
  if(u != v) P[v] = u;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    P[i] = i;
  }

  cin >> M;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> A[i][j];
      if(A[i][j]) {
        union_node(i, j);
      }
    }
  }

  for(int i = 1; i <= M; i++) {
    cin >> B[i];
    if(i==1) continue;
    if(find_node(B[i]) != find_node(B[i-1])) flag = -1;
  }

  if(!flag) cout << "YES";
  else cout << "NO";

  return 0;
}