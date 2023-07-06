#include <iostream>
#include <stack>

using namespace std;

stack<int> S;
int T;
string str;
int X;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  for(int i = 0; i < T; i++) {
    cin >> str;
    if(!str.compare("push")) {
      cin >> X;
      S.push(X);
    } else if(!str.compare("pop")) {
      if(S.empty()) {
        cout << -1 << "\n";
      } else {
        cout << S.top() << "\n";
        S.pop();
      }
    } else if(!str.compare("size")) {
      cout << S.size() << "\n";
    } else if(!str.compare("empty")) {
      cout << (S.empty()?"1":"0") << "\n";
    } else if(!str.compare("top")) {
      if(S.empty()) {
        cout << -1 << "\n";
      } else {
        cout << S.top() << "\n";
      }
    }
  }

  return 0;
}