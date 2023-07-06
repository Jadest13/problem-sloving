#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
using PII = pair<int, int>;
using PIPII = pair<int, PII>;

int N, C;
int a;
map<int, PII> MP;
vector<PIPII> V;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> C;
  for(int i = 1; i <= N; i++) {
    cin >> a;
    if(MP[a].first == 0) MP[a].first = i;
    MP[a].second++;
  }
  for(auto a : MP) {
    V.emplace_back(a.first, a.second);
  }
  sort(V.begin(), V.end(), [](PIPII a, PIPII b) {
    if(a.second.second == b.second.second) return a.second.first < b.second.first;
    else return a.second.second > b.second.second;
  });
  for(auto a : V) {
    for(int i = 0; i < a.second.second; i++) {
      cout << a.first << " ";
    }
  }

  return 0;
}