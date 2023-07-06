#include <iostream>

using namespace std;

int N, M;
int A[101][101];
int a;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> A[i][j];
    }
  }
  
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> a;
      A[i][j] += a;
    }
  }
  
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cout << A[i][j] << " ";
    }
    cout << "\n";
  }

}