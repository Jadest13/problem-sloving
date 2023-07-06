#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<string> maps) {
  int answer = 0;
  int visit[100][100];
  pair<int, int> S, L, E;
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  int R1 = 0, R2 = 0;

  for(int i = 0; i < maps.size(); i++) {
    for(int j = 0; j < maps[i].size(); j++) {
      if(maps[i][j] == 'X') {
        visit[i][j] = 1;
      } else {
        visit[i][j] = 0;
      }
      if(maps[i][j] == 'S') S = {i, j};
      if(maps[i][j] == 'L') L = {i, j};
      if(maps[i][j] == 'E') E = {i, j};
    }
  }

  queue<pair<pair<int, int>, int>> Q1;
  Q1.push({{S.first, S.second}, 0});
  visit[S.first][S.second] = 1;
  while(!Q1.empty()) {
    int px = Q1.front().first.first;
    int py = Q1.front().first.second;
    int pn = Q1.front().second;
    Q1.pop();

    if(maps[px][py] == 'L') {
      R1 = pn;
      break;
    }

    for(int d = 0; d < 4; d++) {
      int nx = px + dx[d];
      int ny = py + dy[d];
      if(nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size()) continue;
      if(visit[nx][ny]) continue;

      Q1.push({{nx, ny}, pn+1});
      visit[nx][ny] = 1;
    }
  }

  for(int i = 0; i < maps.size(); i++) {
    for(int j = 0; j < maps[i].size(); j++) {
      if(maps[i][j] == 'X') {
        visit[i][j] = 1;
      } else {
        visit[i][j] = 0;
      }
    }
  }
  
  queue<pair<pair<int, int>, int>> Q2;
  Q2.push({{L.first, L.second}, 0});
  visit[L.first][L.second] = 1;
  while(!Q2.empty()) {
    int px = Q2.front().first.first;
    int py = Q2.front().first.second;
    int pn = Q2.front().second;
    Q2.pop();

    if(maps[px][py] == 'E') {
      R2 = pn;
      break;
    }

    for(int d = 0; d < 4; d++) {
      int nx = px + dx[d];
      int ny = py + dy[d];
      if(nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size()) continue;
      if(visit[nx][ny]) continue;

      Q2.push({{nx, ny}, pn+1});
      visit[nx][ny] = 1;
    }
  }

  if(!R1 || !R2) answer = -1;
  else answer = R1 + R2;

  return answer;
}

int main() {
  vector<string> maps[] = {
    {"SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"},
    {"LOOXS","OOOOX","OOOOO","OOOOO","EOOOO"}
  };

  for(int i = 0; i < 2; i++) {
    cout << solution(maps[i]) << "\n";
  }
}