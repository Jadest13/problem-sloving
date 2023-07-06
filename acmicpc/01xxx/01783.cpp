#include <iostream>
#include <algorithm>

using namespace std;
using LL = long long;

LL N, M;
LL R;

LL F(int n, int x, int y) {
  LL ret = n;
  if(ret == 4) return ret;
  if(x+1 <= M && y+2 <= N)
    ret = max(ret, F(n+1, x+1, y+2));
  if(x+2 <= M && y+1 <= N)
    ret = max(ret, F(n+1, x+2, y+1));
  if(x+2 <= M && y-1 >= 1)
    ret = max(ret, F(n+1, x+2, y-1));
  if(x+1 <= M && y-2 >= 1)
    ret = max(ret, F(n+1, x+1, y-2));
  return ret;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  if(N >= 3 && M >= 6) {
    R = M-2;
  }
  R = max(R, F(1, 1, 1));

  cout << R;

  return 0;
}