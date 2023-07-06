#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 1000001
#define INF 1e9;

using namespace std;
using LL = long long;
using PII = pair<int, int>;

int N, K;
int A[MAX];
int SUM[MAX];
int R = INF;
priority_queue<PII, vector<PII>, greater<PII>> PQ;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N >> K;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  sort(A+1, A+N+1);
  for(int i = 1; i < N; i++) {
    SUM[i] = SUM[i-1] + A[i+1]-A[i];
  }
  
  int l = 1, r = N-K-1;
  for(int i = l; i < r; i++) {
    PQ.push({A[i+1]-A[i], i});
  }
  while(r < N) {
    while(!PQ.empty() && PQ.top().second < l) {
      PQ.pop();
    }
    PQ.push({A[r+1]-A[r], r});
    int M = SUM[r] - SUM[l-1];
    int m = PQ.top().first;

    R = min(R, M+m);

    l++;
    r++;
  }

  cout << R;
  
  return 0;
}