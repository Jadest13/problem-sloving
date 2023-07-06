#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
using LL = long long;

LL N, P, Q;
map<LL, LL> MP;

LL F(LL n) {
  if(n == 0) return 1;
  if(MP[n]) return MP[n];
  return MP[n] = F(n/P) + F(n/Q);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> P >> Q;
  cout << F(N);

  return 0;
}