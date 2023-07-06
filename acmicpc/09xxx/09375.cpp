#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> M;
string A, B;
int T, N, R;

int main() {

  cin >> T;
  for(int i = 0; i < T; i++) {

    M.clear();
    cin >> N;

    for(int j = 0; j < N; j++) {
      cin >> A >> B;
      if(M.find(B) == M.end()) {
        M.insert({B, 1});
      } else {
        M.find(B)->second += 1;
      }
    }

    R = 1;
    for(auto iter:M) {
      R *= iter.second+1;
    }
    R -= 1;
    cout << R << endl;
  }
  
  return 0;
}