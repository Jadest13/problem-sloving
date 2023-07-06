#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N;
string str;
map<string, int> MP;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> str;
    MP[str]++;
  }
  for(int i = 1; i <= N-1; i++) {
    cin >> str;
    MP[str]--;
  }
  for(auto a : MP) {
    if(a.second == 0) continue;
    cout << a.first;
  }

  return 0;
}