#include <iostream>

using namespace std;

int N, M;
int n;
int a, b;
long D[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> n;
    D[i] = D[i-1] + n;
  }

  for(int i = 0; i < M; i++) {
    cin >> a >> b;
    cout << D[b] - D[a-1] << "\n";
  }

  return 0;
}