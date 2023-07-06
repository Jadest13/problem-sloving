#include <iostream>
#include <algorithm>

using namespace std;

int N;
int DP[1001];

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  DP[1] = 0;
  DP[2] = 1;
  DP[3] = 0;
  DP[4] = 1;

  for(int i = 5; i <= N; i++) {
    if(DP[i-1] + DP[i-3] + DP[i-4] == 3) {
      DP[i] = 0;
    } else {
      DP[i] = 1;
    }
  }

  if(DP[N]) {
    cout << "SK";
  } else {
    cout << "CY";
  }

  return 0;
}