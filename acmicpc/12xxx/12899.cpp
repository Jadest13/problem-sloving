#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 2000001
#define LL long long

using namespace std;

int N;
int T, X;
int SEG[MAX*4];

void seg_add(int n, int s, int e, int x) {
  if(x < s || e < x) return;
  SEG[n]++;
  if(s==e) return;
  int m = (s+e)/2;
  seg_add(n*2, s, m, x);
  seg_add(n*2+1, m+1, e, x);
}

int seg_get(int n, int s, int e, int x) {
  SEG[n]--;
  if(s==e) return s;
  int m = (s+e)/2;
  if(SEG[n*2] >= x) return seg_get(n*2, s, m, x);
  else return seg_get(n*2+1, m+1, e, x-SEG[n*2]);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> T >> X;
    if(T == 1) {
      seg_add(1, 0, MAX, X);
    } else {
      cout << seg_get(1, 0, MAX, X) << "\n";
    }
  }


  return 0;
}