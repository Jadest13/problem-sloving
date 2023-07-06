#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, x;
string str;
int S[21];

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while(T--) {
    cin >> str;
    if(!str.compare("add")) {
      cin >> x;
      S[x] = 1;
    } else if(!str.compare("remove")) {
      cin >> x;
      S[x] = 0;
    } else if(!str.compare("check")) {
      cin >> x;
      cout << S[x] << "\n";
    } else if(!str.compare("toggle")) {
      cin >> x;
      S[x] = !S[x];
    } else if(!str.compare("all")) {
      for(int i = 0; i <= 20; i++) S[i] = 1;
    } else if(!str.compare("empty")) {
      for(int i = 0; i <= 20; i++) S[i] = 0;
    }
  }

  return 0;
}