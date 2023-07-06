#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;
using PSI = pair<string, int>;

int N, K;
char c;
string S, E;
map<string, int> visit;
queue<PSI> Q;
int R = -1;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  for(int i = 1; i <= N; i++) {
    cin >> c;
    S += c;
  }
  E = S;
  sort(E.begin(), E.end());

  Q.push({S, 0});
  visit[S] = 1;
  while(!Q.empty()) {
    string ps = Q.front().first;
    int pn = Q.front().second;
    Q.pop();

    if(ps == E) {
      R = pn;
      break;
    }

    for(int i = 0; i <= N-K; i++) {
      string ns = ps;
      for(int j = 0; j < K/2; j++) {
        swap(ns[i+j], ns[i+K-1-j]);
      }
      if(visit[ns]) continue;
      visit[ns] = 1;
      Q.push({ns, pn+1});
    }
  }

  cout << R;

  return 0;
}