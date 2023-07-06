#include <iostream>
#include <string>
#include <map>

using namespace std;

map<int, int> M;
int A, B, a, R;

int main() {

  cin >> A >> B;
  for(int i = 0; i < A+B; i++) {
    cin >> a;
    if(M.find(a) == M.end()) {
      M.insert({a, 1});
    } else {
      M.find(a)->second += 1;
    }
  }

  for(auto iter:M) {
    if(iter.second == 1) {
      R++;
    }
  }

  cout << R;
  
  return 0;
}