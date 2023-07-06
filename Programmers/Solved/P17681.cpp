//비밀지도
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
  vector<string> answer;

  for(int i = 0; i < n; i++) {
    string str = "";
    for(int j = 0; j < n; j++) {
      str += " ";
    }
    for(int j = 0; j < n; j++) {
      int b = 1 << j;
      if(arr1[i] & b || arr2[i] & b) {
        str[n-j-1] = '#';
      } else {
        str[n-j-1] = ' ';
      }
    }
    answer.push_back(str);
  }

  return answer;
}

int main(void) {
  vector<tuple<int, vector<int>, vector<int>>> n;
  n.push_back({5, {9, 20, 28, 18, 11}, {30, 1, 21, 17, 28}});

  for(int i = 0; i < n.size(); i++) {
    for(auto a : solution(get<0>(n[i]), get<1>(n[i]), get<2>(n[i])))
      cout << a << "\n";
  }

  return 0;
}