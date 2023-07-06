#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
using LL = long long;

int N;
string str;
map<string, int> MP;
LL R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> str;
    if(str == "ENTER") {
      MP.clear();
      continue;
    } else if(MP[str]) continue;
    R++;
    MP[str]++;
  }

  cout << R;

  return 0;
}