#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int D, P, Q;

int solve(int d, int p, int q) {
  if(d%p==0 || d%q==0) return d;
  if(p < q) swap(p, q);
  int pi = d/p+1;
  int mn = pi*p;
  
  for(int i = 1; i <= pi; i++) {
    int tmp = (pi-i)*p;
    if((d-tmp)%q==0) return d;
    else tmp += ((d-tmp)/q+1)*q;
    if(mn == tmp) break;
    mn = min(mn, tmp);
  }
  return mn;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> D >> P >> Q;
  cout << solve(D, P, Q);

  return 0;
}