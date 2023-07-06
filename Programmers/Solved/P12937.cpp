#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int num) {
  string answer = "";

  if(num%2) {
    answer = "Odd";
  } else {
    answer = "Even";
  }

  return answer;
}

int main(void) {
  vector<int> n = {3, 4};

  for(auto a : n) {
    cout << solution(a) << "\n";
  }

  return 0;
}