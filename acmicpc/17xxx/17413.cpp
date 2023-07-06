#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S;
char c;
int a, b;

int main() {
  getline(cin, S);
  a = 0;
  for(int i = 0; i < S.length(); i++) {
    if(S.at(i) == '<' || S.at(i) == ' ') {
      b = i-1;
      for(int j = 0; j <= (b-a-1)/2; j++) {
        c = S.at(a+j);
        S.at(a+j) = S.at(b-j);
        S.at(b-j) = c;
      }

      a = i+1;
    }

    if(S.at(i) == '<') {
      for(; S.at(i) != '>'; i++);
      a = i+1;
    }
  }

  b = S.length()-1;
  if(a <= b) {
    for(int j = 0; j <= (b-a)/2; j++) {
      c = S.at(a+j);
      S.at(a+j) = S.at(b-j);
      S.at(b-j) = c;
    }
  }

  cout << S;

  return 0;
}