#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX INT32_MAX

int N, C;
int a;
vector<long long> A;
vector<long long> V1, V2;
long long sum;

void F(vector<long long> &V, int s, int e, long long a) {
  if(s >= e) V.push_back(a);
  else {
    F(V, s+1, e, a);
    F(V, s+1, e, a+A[s]);
  }
  return;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> C;
  for(int i = 1; i <= N; i++) {
    cin >> a;
    A.push_back(a);
  }
  sort(A.begin(), A.end());

  F(V1, 0, N/2, 0);
  F(V2, N/2, N, 0);

  sort(V1.begin(), V1.end());
  sort(V2.begin(), V2.end());

  for(auto a : V2) {
    int l = upper_bound(V1.begin(), V1.end(), C-a) - V1.begin();
    sum += l;
  }

  cout << sum;

  return 0;
}