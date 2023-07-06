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

  for(int i = 1; i <= 1000; i++) {
    if(i < 3) {
      DP[i] = i;
    } else {
      DP[i] = min(DP[i-1] + 1, DP[i-3] + 1);
    }
  }

  if(DP[N] % 2 == 0) {
    cout << "CY";
  } else {
    cout << "SK";
  }

  return 0;
}