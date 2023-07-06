#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> poke;
string num[100001];
string S;
int N, M;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for(int i = 1; i <= N; i++) {
    cin >> S;
    num[i] = S;
    poke.insert({S, i});
  }
  
  for(int i = 0; i < M; i++) {
    cin >> S;
    if(isdigit(S[0])) {
      cout << num[stoi(S)] << "\n";
    } else {
      cout << poke[S] << "\n";
    }
  }

  return 0;
}