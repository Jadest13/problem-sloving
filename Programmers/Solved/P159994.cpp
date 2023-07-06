#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
  string answer = "";
  int l = 0, r = 0;

  answer = "Yes";

  for(auto a : goal) {
    if(cards1[l] == a) {
      l++;
    } else if(cards2[r] == a) {
      r++;
    } else {
      answer = "No";
      break;
    }
  }

  return answer;
}

int main() {
  vector<string> cards1[] = {
    {"i", "drink", "water"},
    {"i", "drink", "water"},
    {"i", "drink"},
    {"i", "water", "drink"}
  };
  vector<string> cards2[] = {
    {"want", "to"},
    {"want", "to"},
    {"want", "to"},
    {"want", "to"}
  };
  vector<string> goal[] = {
    {"i", "want", "to", "drink", "water"},
    {"i", "want", "water"},
    {"i", "want", "to", "drink", "water"},
    {"i", "want", "to", "drink", "water"}
  };

  for(int i = 0; i < 4; i++) {
    cout << solution(cards1[i], cards2[i], goal[i]);
  }
}