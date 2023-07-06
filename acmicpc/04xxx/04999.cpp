#include <iostream>
#include <algorithm>

using namespace std;

string A, B;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B;
  if(A.length() >= B.length()) cout << "go";
  else cout << "no";

  return 0;
}