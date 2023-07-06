#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int N;
string str;
map<string, int> MP;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> str;
    MP[str.substr(str.find('.')+1)]++;
  }
  for(auto a : MP) {
    cout << a.first << " " << a.second << "\n";
  }


  return 0;
}