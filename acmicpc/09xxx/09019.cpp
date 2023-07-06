#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define MAX INT32_MAX

using namespace std;

int T;
int A, B;
int V[10000];
pair<int, string> DSLR[4];

string F() {
  queue<pair<int, string>> Q;
  Q.push({A, ""});
  V[A] = 1;

  while(!Q.empty()) {
    int n = Q.front().first;
    string str = Q.front().second;
    Q.pop();

    if(n == B) return str;

    DSLR[0] = {(n*2)%10000, "D"};
    DSLR[1] = {(n+9999)%10000, "S"};
    DSLR[2] = {n/1000 + (n%1000)*10, "L"};
    DSLR[3] = {n/10 + (n%10)*1000, "R"};

    for(auto a : DSLR) {
      if(!V[a.first]) {
        V[a.first] = 1;
        Q.push({a.first, str + a.second});
      }
    }
  }

  return "";
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while(T--) {
    memset(V, 0, sizeof(V));
    
    cin >> A >> B;
    cout << F() << "\n";
  }

  
  return 0;
}