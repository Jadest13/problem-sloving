#include <iostream>

using namespace std;

int K;
int dir[7], dist[7];
int Mx, My, m, R;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> K;
  for(int i = 1; i <= 6; i++) {
    cin >> dir[i] >> dist[i];
  }
  dir[0] = dir[6];
  dist[0] = dist[6];

  for(int i = 0; i < 6; i++) {
    if(dir[i] == 1 || dir[i] == 2) {
      if(dist[i] > Mx) {
        Mx = dist[i];
      }
    } else if(dir[i] == 3 || dir[i] == 4) {
      if(dist[i] > My) {
        My = dist[i];
      }
    }

    if((dir[i] == 1 && dir[i+1] == 3)
    || (dir[i] == 2 && dir[i+1] == 4)
    || (dir[i] == 3 && dir[i+1] == 2)
    || (dir[i] == 4 && dir[i+1] == 1)) {
      m = dist[i] * dist[i+1];
    }
  }

  R = (Mx * My - m) * K;
  cout << R;

  return 0;
}