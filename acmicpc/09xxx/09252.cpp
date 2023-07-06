#include <bits/stdc++.h>

#define MAX 1001

using namespace std;

string S1, S2;
int DP[MAX][MAX];
vector<char> V;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> S1 >> S2;

  for(int i = 1; i <= S1.length(); i++) {
    for(int j = 1; j <= S2.length(); j++) {
      if(S1[i-1] == S2[j-1]) {
        DP[i][j] = DP[i-1][j-1] + 1;
      } else {
        DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
      }
    }
  }

  int i = S1.length();
  int j = S2.length();

  cout << DP[i][j] << "\n";

  while(i > 0 && j > 0) {
    if(DP[i][j] == DP[i-1][j]) {
      i--;
    } else if (DP[i][j] == DP[i][j-1]) {
      j--;
    } else {
      V.push_back(S1[i-1]);
      i--;
      j--;
    }
  }

  reverse(V.begin(), V.end());
  for(auto a : V) {
    cout << a;
  }

  return 0;
}