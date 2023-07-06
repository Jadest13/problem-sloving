#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
using PSI = pair<string, int>;

int N, M;
string str;
map<string, int> MP;
vector<PSI> V;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> str;
    MP[str]++;
  }
  for(auto a : MP) {
    if(a.first.length() < M) continue;
    V.push_back(a);
  }
  sort(V.begin(), V.end(), [](PSI a, PSI b) {
    if(a.second == b.second) {
      if(a.first.length() == b.first.length())
        return a.first < b.first;
      else return a.first.length() > b.first.length();
    } else return a.second > b.second;
  });
  for(auto a : V) {
    cout << a.first << "\n";
  }


  return 0;
}