#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> M;
string S;
int N = 0;

int main() {

  while((!cin.eof())&&getline(cin, S)) {
    N++;
    if(M.find(S) == M.end()) {
      M.insert({S, 1});
    } else {
      M.find(S)->second += 1;
    }
  }

  cout << fixed;
  cout.precision(4);
  
  for(auto iter:M) {
    cout << iter.first << " " << (iter.second*100.0/N) << endl;
  }

  return 0;
}