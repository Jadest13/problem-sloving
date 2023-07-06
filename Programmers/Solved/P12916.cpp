#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
  bool answer = true;

  int p = 0, y = 0;
  for(auto a : s) {
    if(a == 'p' || a == 'P') p++;
    if(a == 'y' || a == 'Y') y++;
  }
  answer = p==y;

  return answer;
}

int main(void) {
  vector<string> n = {"pPoooyY", "Pyy"};

  for(auto a : n) {
    cout << solution(a) << "\n";
  }

  return 0;
}