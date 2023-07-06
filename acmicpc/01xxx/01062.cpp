#include <bits/stdc++.h>

#define MAX 51

using namespace std;

int N, K;
int A[26];
string str[MAX];

int DFS(int n, int cnt) {
  int ret = 0;
  if(cnt == K) {
    for(int i = 1; i <= N; i++) {
      int flag = 1;
      for(auto a : str[i]) {
        if(!A[a-'a']) {
          flag = 0;
          break;
        }
      }
      ret += flag;
    }
    return ret;
  }

  for(int i = n; i < 26; i++) {
    if(A[i]) continue;
    A[i] = 1;
    ret = max(ret, DFS(i, cnt+1));
    A[i] = 0;
  }
  return ret;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N >> K;
  for(int i = 1; i <= N; i++) {
    cin >> str[i];
  }

  A['a'-'a'] = A['c'-'a'] = A['i'-'a'] = A['n'-'a'] = A['t'-'a'] = 1;
  K -= 5;

  cout << ((K>=0)?DFS(0, 0):0);
  
  return 0;
}
