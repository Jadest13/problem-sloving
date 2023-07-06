#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int A[10001];
int s, e;
int sum, res;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  s = e = 1;
  sum = A[s];
  while(s <= e && e <= N) {
    if(sum < M) sum += A[++e];
    else if(sum == M) {
      res++;
      sum += A[++e];
    } else if(sum > M) {
      sum -= A[s++];
      if(s > e) {
        e = s;
        sum = A[s];
      }
    }
  }

  cout << res;
}