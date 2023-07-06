#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
using LL = long long;

int N;
int a;
LL C;
map<int, int> MP;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  MP[0] = -1;
  MP[300001] = -1;
  for(int i = 1; i <= N; i++) {
    cin >> a;
    auto r = MP.upper_bound(a);
    auto l = r;
    l--;

    int d = max(l->second, r->second) + 1;
    MP[a] = d;
    C += d;
    cout << C << "\n";
  }

  return 0;
}