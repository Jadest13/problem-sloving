#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N;
string str;
map<string, int> MP;
int flag;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> str;
    MP[str] = 1;
    reverse(str.begin(), str.end());
    flag = 0;
    for(auto a : MP) {
      if(a.first == str) {
        flag = 1;
        break;
      }
    }
    if(flag) {
      cout << str.length() << " " << str[str.length()/2];
      break;
    }
    MP[str] = 1;
  }

  return 0;
}