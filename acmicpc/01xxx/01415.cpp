#include <bits/stdc++.h>

#define MAX 10001

using namespace std;
using LL = long long;
using PII = pair<int, int>;

int N;
int a;
int A[MAX];
int prime[MAX*50];
LL zero = 1;
LL DP[MAX*50];
vector<PII> V;
LL R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> a;
    if(a == 0) zero++;
    else A[a]++;
  }
  for(int i = 0; i < MAX; i++) {
    if(!A[i]) continue;
    V.push_back({i, A[i]});
  }

  DP[0] = 1;
  for(auto a : V) {
    for(int i = N*10000; i >= 0; i--) {
      for(int j = 1; j <= a.second; j++) {
        if(i-a.first*j < 0) break;
        DP[i] += DP[i-a.first*j];
      }
    }
  }

  for(int i = 2; i <= N*10000; i++) {
    if(prime[i]) continue;
    prime[i] = 1;
    for(int j = i*2; j <= N*10000; j += i) {
      prime[j] = -1;
    }
  }

  for(int i = 0; i <= N*10000; i++) {
    if(prime[i] == 1) R += DP[i];
  }

  cout << zero * R;

  return 0;
}