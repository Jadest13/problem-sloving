#include <iostream>
#include <string>

using namespace std;

string A, B;
int R;

int main() {

  getline(cin, A);
  getline(cin, B);

  for(int i = 0; i < A.length(); i++) {
    if(!B.compare(A.substr(i, B.length()))) {
      i += B.length()-1;
      R++;
    }
  }

  cout << R;

  return 0;
}