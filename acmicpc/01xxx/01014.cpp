#include <iostream>
#include <vector>

using namespace std;

int C;
int N, M;
char A[10][10];
int bit[10][1<<10];
vector<string> V;
int tmp[10];

void DFS(int idx) {
  if(idx == M) {
    string str;
    for(int i = 0; i < M; i++) {
      if(tmp[i]) str += "1";
      else str += "0";
    }
    V.push_back(str);
    return;
  }
  tmp[idx] = 0;
  DFS(idx+1);
  if(idx && tmp[idx-1]) {
    return;
  }
  tmp[idx] = 1;
  DFS(idx+1);
}

int DP(int l, int bef) {
  if(l == N) return 0;
  if(bit[l][bef] > -1) return bit[l][bef];

  bit[l][bef] = 0;

  for(auto a : V) {
    int bits = 0;
    int cnt = 0;
    for(int i = 0; i < M; i++) {
      if(a[i] == '0') continue;
      if(A[l][i] == 'x') continue;
      if(i > 0 && bef & (1 << (i-1))) continue;
      if(i < M-1 && bef & (1 << (i+1))) continue;

      cnt++;
      bits |= (1 << i);
    }

    bit[l][bef] = max(bit[l][bef], DP(l+1, bits)+cnt);
  }

  return bit[l][bef];
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> C;
  while(C--) {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < (1 << M); j++) {
        bit[i][j] = -1;
      }
    }
    V.clear();
    DFS(0);
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        cin >> A[i][j];
      }
    }
    cout << DP(0, 0) << "\n";
  }
}