#include <iostream>
#include <algorithm>

#define MAX 101

using namespace std;

int N, M;
int s, e, m;
int A[MAX];
int tmp[MAX];

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    A[i] = i;
  }
  for(int i = 1; i <= M; i++) {
    cin >> s >> e >> m;
    for(int j = s; j <= e; j++) {
      int a = j-s+m;
      if(a > e) a = s + (a-e) -1;
      tmp[j] = A[a];
    }
    for(int j = s; j <= e; j++) {
      A[j] = tmp[j];
    }
  }
  for(int i = 1; i <= N; i++) {
    cout << A[i] << " ";
  }

  return 0;
}