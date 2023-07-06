#include <iostream>
#include <algorithm>

#define MAX 1000001

using namespace std;

int N, M;
int A[MAX], B[MAX];

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  for(int i = 1; i <= M; i++) {
    cin >> B[i];
  }
  int l = 1, r = 1;
  while(l <= N && r <= M) {
    if(A[l] <= B[r]) cout << A[l++] << " ";
    else cout << B[r++] << " ";
  }
  while(l <= N) cout << A[l++] << " ";
  while(r <= M) cout << B[r++] << " ";

  return 0;
}