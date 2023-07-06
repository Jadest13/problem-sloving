#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <string>

using namespace std;
using PSI = pair<string, int>;

string G;
char c;
set<string> visit;
queue<PSI> Q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int R = -1;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i = 0; i < 9; i++) {
    cin >> c;
    G += c;
  }

  visit.insert(G);
  Q.push({G, 0});

  while(!Q.empty()) {
    string pg = Q.front().first;
    int pn = Q.front().second;
    Q.pop();

    if(pg == "123456780") {
      R = pn;
      break;
    }

    int pp = pg.find('0');
    int px = pp%3;
    int py = pp/3;
    
    for(int i = 0; i < 4; i++) {
      int nx = px + dx[i];
      int ny = py + dy[i];
      if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
      string ng = pg;
      swap(ng[py*3+px], ng[ny*3+nx]);
      if(visit.find(ng) != visit.end()) continue;
      visit.insert(ng);
      Q.push({ng, pn+1});
    }
  }

  cout << R;

  return 0;
}