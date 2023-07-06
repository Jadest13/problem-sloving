#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S, R[1001];

int main() {

  getline(cin, S);

  for(int i = 0; i < S.length(); i++) {
    R[i] = S.substr(i, S.length() - i);
  }

  sort(R, R+S.length());

  for(int i = 0; i < S.length(); i++) {
    cout << R[i] << "\n";
  }

  return 0;
}