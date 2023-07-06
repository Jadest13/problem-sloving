#include <iostream>
#include <string>

using namespace std;

string S, E, R;
int len;

int main() {
  getline(cin, S);
  getline(cin, E);

  R = "";

  for(int i = 0; i < S.length(); i++) {
    R += S[i];
    if(R.length() >= E.length() && !E.compare(R.substr(R.length() - E.length(), E.length()))) {
      for(int j = 0; j < E.length(); j++) {
        R.pop_back();
      }
    }
  }


  if(R.length() == 0) {
    R = "FRULA";
  }
  
  cout << R;

  return 0;
}