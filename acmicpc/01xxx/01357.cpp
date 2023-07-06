#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string X, Y;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> X >> Y;
  reverse(X.begin(), X.end());
  reverse(Y.begin(), Y.end());
  int r = stoi(X) + stoi(Y);
  string R = to_string(r);
  reverse(R.begin(), R.end());
  
  cout << stoi(R);

  return 0;
}