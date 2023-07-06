#include <iostream>
#include <algorithm>

using namespace std;

int T;
string S;
int l, r;
int cnt, res;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  for(int i = 1; i <= T; i++) {
    cin >> S;
    cnt = 0;
    res = 1;
    for(l = 0, r = S.length()-1; l <= r+1; l++, r--) {
      cnt++;

      if(S[l] != S[r]) {
        res = 0;
        break;
      }
    }
    cout << res << " " << cnt << "\n";
  }

  return 0;
}