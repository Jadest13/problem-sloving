#include <bits/stdc++.h>

#define MAX 5001

using namespace std;

int N;
int ARR[MAX];
int DP[MAX][MAX];

int F(int s, int e) {
  if(s >= e) return 0;
  if(DP[s][e] != -1) return DP[s][e];

  if(ARR[s] == ARR[e]) return DP[s][e] = F(s+1, e-1);
  else return DP[s][e] = 1 + min(F(s+1, e), F(s, e-1));
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> ARR[i];
  }

  memset(DP, -1, sizeof(DP));
  cout << F(1, N);

  return 0;
}