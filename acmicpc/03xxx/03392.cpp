#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 30001

using namespace std;

typedef struct {
  int x, y1, y2, left;
} Line;

int N;
int x1, y1, x2, y2;
vector<Line> V;
int SEG[MAX*4], CNT[MAX*4];
int R;

void segUpdate(int n, int s, int e, int l, int r, int a) {
  if(e < l || r < s) return;
  if(l <= s && e <= r) CNT[n] += a;
  else {
    int m = (s+e)>>1;
    segUpdate(n*2, s, m, l, r, a);
    segUpdate(n*2+1, m+1, e, l, r, a);
  }

  if(CNT[n]) {
    SEG[n] = e-s+1;
  } else {
    if(s==e) SEG[n] = 0;
    else SEG[n] = SEG[n*2] + SEG[n*2+1];
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    V.push_back({x1, y1, y2, 1});
    V.push_back({x2, y1, y2, -1});
  }
  sort(V.begin(), V.end(), [](Line a, Line b) {
    return a.x < b.x;
  });

  for(int i = 0; i < V.size(); i++) {
    if(i) R += (V[i].x - V[i-1].x) * SEG[1];
    segUpdate(1, 0, MAX-1, V[i].y1, V[i].y2-1, V[i].left);
  }

  cout << R;

  return 0;
}