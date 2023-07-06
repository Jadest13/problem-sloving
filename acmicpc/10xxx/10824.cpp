#include <iostream>
#include <algorithm>

using namespace std;

string A, B, C, D;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B >> C >> D;
  cout << atoll((A+B).c_str()) + atoll((C+D).c_str());

  return 0;
}