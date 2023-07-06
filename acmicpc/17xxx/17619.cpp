#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;

typedef struct {
  int i, x1, x2, y;
} Log;

int N, Q;
int x1, x2, y;
int a, b;
Log ARR[MAX];
int l;
int pos;
int P[MAX];

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> Q;
  for(int i = 1; i <= N; i++) {
    cin >> x1 >> x2 >> y;
    ARR[i] = {i, x1, x2, y};
  }
  sort(ARR+1, ARR+N+1, [](Log a, Log b) {
    return a.x1 < b.x1;
  });

  pos = ARR[1].x1;
  l = 1;
  P[1] = l;
  for(int i = 1; i <= N; i++) {
    if(ARR[i].x1 <= pos) {
      pos = max(pos, ARR[i].x2);
    } else {
      l++;
      pos = ARR[i].x2;
    }
    P[ARR[i].i] = l;
  }
  
  for(int i = 1; i <= Q; i++) {
    cin >> a >> b;
    if(P[a] == P[b]) cout << "1\n";
    else cout << "0\n";
  }

  return 0;
}