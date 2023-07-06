#include <iostream>
#include <algorithm>

using namespace std;

string str;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str;
  for(int i = 0; i < str.length(); i++) {
    if(i==0 || i > 0 && str[i-1] == '-') {
      cout << str[i];
    }
  }

  return 0;
}