#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using PII = pair<int, int>;

int N;
int S, T;
vector<PII> V;
priority_queue<PII, vector<PII>, greater<PII>> PQ;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> S >> T;
    V.push_back({S, T});
  }
  sort(V.begin(), V.end());

  PQ.push({V[0].second, V[0].first});
  for(int i = 1; i < N; i++) {
    PII p = PQ.top();
    if(V[i].first >= p.first) {
      PQ.pop();
      PQ.push({V[i].second, p.first});
    } else {
      PQ.push({V[i].second, V[i].first});
    }
  }

  cout << PQ.size();

  return 0;
}