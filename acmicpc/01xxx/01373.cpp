#include <iostream>
#include <algorithm>

using namespace std;

string str;
int a;
string R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str;
  for(int i = 0; i < str.length(); i++) {
    if(i && i%3 == 0) {
      R.push_back(a+'0');
      a = 0;
    }
    if(i%3 == 0) a += 1*(str[str.length()-1-i]-'0');
    if(i%3 == 1) a += 2*(str[str.length()-1-i]-'0');
    if(i%3 == 2) a += 4*(str[str.length()-1-i]-'0');
  }
  if(a) R.push_back(a+'0');
  if(R.empty()) cout << 0;
  else {
    for(int i = R.length()-1; i >= 0; i--) {
      cout << R[i];
    }
  }

  return 0;
}