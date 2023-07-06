#include <iostream>
#include <algorithm>

#define MAX 1000001

using namespace std;
using LL = long long;

LL mn, mx;
int ARR[MAX];
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> mn >> mx;

  for(LL i = 2; i*i <= mx; i++) {
    LL n = mn / (i*i);
    if(mn % (i*i)) n++;

    while(n*i*i <= mx) {
      ARR[n*i*i - mn] = 1;
      n++;
    }
  }

  for(int i = 0; i <= mx-mn; i++) {
    if(!ARR[i]) R++;
  }

  cout << R;

  return 0;
}