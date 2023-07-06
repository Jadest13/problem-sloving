#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int A[101];
int T[101];
int flag;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for(int i = 1; i <= K; i++) {
    cin >> A[i];
  }

  for(int i = 1; i <= K; i++) {
    flag = 0;
    for(int j = 1; j <= N; j++) {
      if(T[j] == A[i]) {
        flag = 1;
        break;
      }
    }
    if(flag) continue;

    for(int j = 1; j <= N; j++) {
      if(!T[j]) {
        T[j] = A[i];
        flag = 1;
        break;
      }
    }
    if(flag) continue;

    int idx = 0, m = 0;
    for(int j = 1; j <= N; j++) {
      int tmp = 1;
      for(int k = i+1; k <= K; k++) {
        if(A[k] == T[j]) break;
        tmp++;
      }
      if(tmp > m) {
        idx = j;
        m = tmp;
      }
    }

    T[idx] = A[i];
    R++;
  }
  cout << R;

  return 0;
}