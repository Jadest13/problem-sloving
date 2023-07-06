#include <iostream>
#include <algorithm>

using namespace std;

string str;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str;
  for(int i = 0; i < str.length(); i++) {
    if(!i || str[i] != str[i-1]) R += 10;
    else R += 5;
  }

  cout << R;

  return 0;
}