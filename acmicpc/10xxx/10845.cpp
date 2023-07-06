#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int T, X;
string S;
list<int> Q;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while(T--) {
    cin >> S;
    if(!S.compare("push")) {
      cin >> X;
      Q.push_back(X);
    } else if(!S.compare("pop")) {
      if(Q.empty()) cout << -1;
      else {
        cout << Q.front();
        Q.pop_front();
      }
    } else if(!S.compare("size")) {
      cout << Q.size();
    } else if(!S.compare("empty")) {
      if(Q.empty()) cout << 1;
      else cout << 0;
    } else if(!S.compare("front")) {
      if(Q.empty()) cout << -1;
      else cout << Q.front();
    } else if(!S.compare("back")) {
      if(Q.empty()) cout << -1;
      else cout << Q.back();
    }
    
    if(S.compare("push")) {
      cout << "\n";
    }
  }

  return 0;
}