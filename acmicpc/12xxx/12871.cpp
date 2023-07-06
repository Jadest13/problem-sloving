#include <iostream>
#include <string>

using namespace std;

string A, B;
string X, Y;

int main() {

  getline(cin, A);
  getline(cin, B);

  X = A;
  for(int i = A.length() - 1; i > 0; i--) {
    int r = 1;
    for(int j = i; j < A.length(); j += i) {
      if(A.substr(0, i).compare(A.substr(j, i))) {
        r = 0;
        break;
      }
    }
    if(r) {
      X = A.substr(0, i);
    }
  }
  
  Y = B;
  for(int i = B.length() - 1; i > 0; i--) {
    int r = 1;
    for(int j = i; j < B.length(); j += i) {
      if(B.substr(0, i).compare(B.substr(j, i))) {
        r = 0;
        break;
      }
    }
    if(r) {
      Y = B.substr(0, i);
    }
  }

  if(!X.compare(Y)) {
    cout << 1;
  } else {
    cout << 0;
  }

  return 0;
}