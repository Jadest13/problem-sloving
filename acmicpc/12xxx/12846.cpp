#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using LL = long long;

typedef struct {
  LL a;
  int s, e;
} Pay;

LL N;
int A;
vector<Pay> V;
LL R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  V.push_back({0, 0, 0});
  for(int i = 1; i <= N; i++) {
    cin >> A;
    while(V.back().a > A) {
      R = max(R, V.back().a*(i-V.back().s));
      V.pop_back();
    }
    if(V.back().a == A) V.back().e = i;
    else V.push_back({A, i, i});
  }
  
  for(int i = 1; i < V.size(); i++) {
    R = max(R, V[i].a*(N - V[i-1].e));
  }

  cout << R;

  return 0;
}