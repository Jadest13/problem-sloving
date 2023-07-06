#include <iostream>
#include <algorithm>

using namespace std;

string A, B;
int DP[41][41];
string R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B;
  for(int i = 1; i <= B.length(); i++) {
    for(int j = 1; j <= A.length(); j++) {
      if(B[i-1] == A[j-1]) DP[i][j] = DP[i-1][j-1] + 1;
      else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
    }
  }

  for(int i = B.length(), j = A.length(); i && j;) {
    if(DP[i][j] == DP[i-1][j]) i--;
    else if(DP[i][j] == DP[i][j-1]) j--;
    else {
      R.push_back(B[i-1]);
      i--; j--;
    }
  }

  reverse(R.begin(), R.end());
  cout << R;

  return 0;
}