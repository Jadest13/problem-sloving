#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

string S;
int R;
int DP[51][51];

int F(int l, int r) {
  if(DP[l][r] != -1) return DP[l][r];
  if(l >= r) return 0;
  DP[l][r] = min({F(l+1, r) + 1, F(l, r-1) + 1, F(l+1, r-1) + (S[l]!=S[r])});
  return DP[l][r];
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> S;

  memset(DP, -1, sizeof(DP));
  R = F(0, S.length()-1);

  for(int i = 0; i < S.length(); i++) {
    for(int j = i+1; j < S.length(); j++) {
      memset(DP, -1, sizeof(DP));
      swap(S[i], S[j]);
      R = min(R, F(0, S.length()-1) + 1);
      swap(S[i], S[j]);
    }
  }

  cout << R;

  return 0;
}