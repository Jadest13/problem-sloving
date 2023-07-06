//비밀지도
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
  int answer = 0;

  vector<string> V;
  for(auto a : cities) {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    auto iter = find(V.begin(), V.end(), a);
    if(iter != V.end()) {
      V.erase(iter);
      V.push_back(a);
      answer++;
    } else {
      if(V.size() < cacheSize) {
        V.push_back(a);
      } else if(!V.empty()) {
        V.erase(V.begin());
        V.push_back(a);
      }
      answer += 5;
    }
  }

  return answer;
}

int main(void) {
  vector<pair<int, vector<string>>> n;
  n.push_back({3, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"}});

  for(auto a : n) {
    cout << solution(a.first, a.second) << "\n";
  }

  return 0;
}