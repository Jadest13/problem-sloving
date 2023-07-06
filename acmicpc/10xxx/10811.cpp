#include <iostream>
#include <algorithm>

#define MAX 101

using namespace std;

int N, M;
int u, v;
int A[MAX];

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    A[i] = i;
  }
  for(int i = 1; i <= M; i++) {
    cin >> u >> v;
    for(int j = u; j <= (u+v)/2; j++) {
      swap(A[j], A[v-(j-u)]);
    }
  }
  for(int i = 1; i <= N; i++) {
    cout << A[i] << " ";
  }

  return 0;
}