#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX INT32_MAX

int L, n, a;
vector<int> S;
int A, B;
bool b = true;
long R;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> L;
  for(int i = 1; i <= L; i++) {
    cin >> a;
    S.push_back(a);
  }
  cin >> n;

  S.push_back(0);
  sort(S.begin(), S.end());
  for(int i = 0; i < L; i++) {
    if(n == S[i]) {
      b = false;
      break;
    }
  }

  if(b) {
    for(int i = 1; i <= L; i++) {
      if(S[i] > n) {
        A = S[i-1];
        B = S[i];
        break;
      }
    }

    for(int i = A+1; i < B; i++) {
      for(int j = i+1; j < B; j++) {
        if(n >= i && n <= j) {
          R++;
        }
      }
    }
  }

  cout << R;

  return 0;
}