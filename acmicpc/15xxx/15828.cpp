#include <iostream>
#include <queue>

using namespace std;

queue<int> Q;
int N;
int p;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  while(true) {
    cin >> p;
    if(p == -1) break;
    if(p == 0) {
      Q.pop();
      continue;
    }
    if(Q.size() >= N) continue;
    Q.push(p);
  }

  if(Q.empty()) cout << "empty";
  else {
    while(!Q.empty()) {
      cout << Q.front() << " ";
      Q.pop();
    }
  }
}