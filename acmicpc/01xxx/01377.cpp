#include <bits/stdc++.h>

#define MAX 500001

using namespace std;

using PII = pair<int, int>;

int N;
PII A[MAX];
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A+1, A+N+1);
  for(int i = 1; i <= N; i++) {
    if(A[i].second - i > 0) {
      R = max(R, A[i].second - i);
    }
  }

  cout << R+1;

  return 0;
}