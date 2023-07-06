#include <iostream>
#include <algorithm>

#define MAX 100002

using namespace std;

int N, M;
int ARR[MAX];
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= M; i++) {
    cin >> ARR[i];
  }

  R = ARR[1];
  for(int i = 1; i < M; i++) {
    int a = ARR[i+1]-ARR[i];
    if(a > 2*R) {
      R+= (a-2*R+1)/2;
    }
  }
  if(N-ARR[M] > R) R = N-ARR[M];

  cout << R;

  return 0;
}