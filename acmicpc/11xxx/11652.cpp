#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
using LL = long long;

int N;
LL A;
map<LL, int> MP;
LL cnt, R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A;
    MP[A]++;
    if(MP[A] > cnt || (MP[A] == cnt && A < R)) {
      R = A;
      cnt = MP[A];
    }
  }

  cout << R;

  return 0;
}