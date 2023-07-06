#include <iostream>
#include <string>
#include <map>

using namespace std;

map<int, int> m;
int N, M, num;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> num;
    m.insert({num, 1});
  }

  cin >> M;
  for(int i = 0; i < M; i++) {
    cin >> num;
    if(m.find(num) == m.end()) {
      cout << 0 << " ";
    } else {
      cout << 1 << " ";
    }
  }

  return 0;
}