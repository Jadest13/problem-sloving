#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

int N, K;
int a, b;
vector<PII> V;
vector<int> C;
priority_queue<int> PQ;
LL R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  for(int i = 0; i < N; i++) {
    cin >> a >> b;
    V.push_back({a, b});
  }
  for(int i = 0; i < K; i++) {
    cin >> a;
    C.push_back(a);
  }
  sort(V.begin(), V.end());
  sort(C.begin(), C.end());

  for(int i = 0, j = 0; i < K; i++) {
    while(j < N && C[i] >= V[j].first) {
      PQ.push(V[j].second);
      j++;
    }
    if(!PQ.empty()) {
      R += PQ.top();
      PQ.pop();
    }
  }

  cout << R;

  return 0;
}