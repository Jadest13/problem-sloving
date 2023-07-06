#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
using PSI = pair<string, int>;

int K, L;
string a;
map<string, int> MP;
vector<PSI> V;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> K >> L;
  for(int i = 1; i <= L; i++) {
    cin >> a;
    MP[a] = i;
  }
  for(auto a : MP) {
    V.push_back(a);
  }
  sort(V.begin(), V.end(), [](PSI a, PSI b){
    return a.second < b.second;
  });
  for(int i = 0; i < K && i < V.size(); i++) {
    cout << V[i].first << "\n";
  }

  return 0;
}