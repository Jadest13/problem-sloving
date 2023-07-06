#include <iostream>
#include <algorithm>

using namespace std;

string str;
int flag = 1;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str;
  for(int i = 0; i <= (str.length()-1)/2; i++) {
    if(str[i] != str[str.length()-1-i]) flag = 0;
  }
  cout << flag;

  return 0;
}