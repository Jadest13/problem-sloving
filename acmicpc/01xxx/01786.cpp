#include <iostream>
#include <vector>

using namespace std;

string T, P;
vector<int> V, tmp;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  getline(cin, T);
  getline(cin, P);

  for(int i = 0; i < T.length(); i++) {
    if(T[i] == P[0]) V.push_back(i);
  }

  for(int i = 1; i < P.length(); i++) {
    for(auto a : V) {
      if(a+1 < T.length() && T[a+1] == P[i]) {
        tmp.push_back(a+1);
      }
    }
    V.clear();
    V = tmp;
    tmp.clear();
  }

  cout << V.size() << "\n";
  for(auto a : V) {
    cout << (a+1)-P.length()+1 << " ";
  }
}