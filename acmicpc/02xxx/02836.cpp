#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

int N, M;
int a, b;
vector<PII> V;
int pos;
LL R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> a >> b;
    if(b < a) V.push_back({b, a});
  }
  sort(V.begin(), V.end(), [](PII a, PII b) {
    return a.first < b.first;
  });

  pos = V[0].first;
  for(auto a : V) {
    if(a.second <= pos) continue;
    if(pos < a.first) pos = a.first;
    R += a.second - pos;
    pos = a.second;
  }

  cout << R*2+M;

  return 0;
}