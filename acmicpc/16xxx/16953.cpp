#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

int A, B;
queue<PLL> Q;
int R = -1;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B;
  Q.push({A, 1});
  while(!Q.empty()) {
    PLL p = Q.front();
    Q.pop();
    
    if(p.first==B) {
      R = p.second;
      break;
    }

    if(p.first*2 <= B) Q.push({p.first*2, p.second+1});
    if(p.first*10+1 <= B) Q.push({p.first*10+1, p.second+1});
  }

  cout << R;

  return 0;
}