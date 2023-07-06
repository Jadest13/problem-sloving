#include <iostream>
#include <algorithm>

using namespace std;

int N;
int x1, x2, y1, y2, p1, p2, q1, q2;
int X, Y;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i = 1; i <= 4; i++) {
    cin >> x1 >> y1 >> p1 >> q1;
    cin >> x2 >> y2 >> p2 >> q2;
    
    X = min(p1, p2) - max(x1, x2);
    Y = min(q1, q2) - max(y1, y2);

    if(X > 0 && Y > 0) cout << "a";
    else if(X < 0 || Y < 0) cout << "d";
    else if(X == 0 && Y == 0) cout << "c";
    else cout << "b";
    cout << "\n";
  }

  return 0;
}