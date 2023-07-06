#include <iostream>
#include <algorithm>

using namespace std;

string str;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(1) {
    getline(cin, str);
    if(cin.eof()) break;
    int a = 0, b = 0, c = 0, d = 0;
    for(auto e : str) {
      if('a' <= e && e <= 'z') a++;
      if('A' <= e && e <= 'Z') b++;
      if('0' <= e && e <= '9') c++;
      if(e == ' ') d++;
    }
    cout << a << " " << b << " " << c << " " << d << "\n";
  }

  return 0;
}