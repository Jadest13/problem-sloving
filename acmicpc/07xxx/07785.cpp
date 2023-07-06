#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
using LL = long long;

int N;
string A, B;
map<string, int> MP;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A >> B;
    if(B == "enter") MP[A] = 1;
    else MP[A] = 0;
  }

  for(auto a = MP.rbegin(); a != MP.rend(); a++) {
    if(a->second) cout << a->first << "\n";
  }

  return 0;
}