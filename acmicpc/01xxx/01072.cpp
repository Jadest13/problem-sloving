#include <iostream>
#include <algorithm>

#define INF 1e10

using namespace std;
using LL = long long;

LL X, Y;
LL Z;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> X >> Y;
  Z = Y*100/X;
  
  LL l = 1, r = INF;
  LL m;
  while(l < r) {
    m = (l+r)>>1;
    if((Y+m)*100/(X+m) == Z) {
      l = m+1;
    } else {
      r = m;
    }
  }

  cout << ((l==INF)?-1:l);

  return 0;
}