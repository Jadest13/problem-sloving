#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  int answer = 0;

  int b = 1;
  int i = 0;
  if(s[0] == '+') {
    b = 1;
    i++;
  } else if(s[0] == '-') {
    b = -1;
    i++;
  }
  for(i; i < s.length(); i++) {
    answer *= 10;
    answer += s[i]-'0';
  }
  answer *= b;

  return answer;
}

int main(void) {
  vector<string> n = {"1234", "-1234"};

  for(auto a : n) {
    cout << solution(a) << "\n";
  }

  return 0;
}