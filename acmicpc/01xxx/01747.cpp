#include <bits/stdc++.h>

#define MAX 10000001

using namespace std;

int P[MAX];
int N;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(long long i = 2; i < MAX; i++) {
    if(P[i]) continue;
    P[i] = 1;
    for(long long j = i*i; j < MAX; j += i) {
      P[j] = -1;
    }
  }

  cin >> N;
  for(int i = N; i < MAX; i++) {
    if(P[i] != 1) continue;
    string s = to_string(i);
    int l = 0, r = s.size()-1;
    int flag = 1;
    while(l < r) {
      if(s[l] != s[r]){ 
        flag = 0;
        break;
      }
      l++;
      r--;
    }
    if(flag) {
      cout << i;
      break;
    }
  }

  return 0;
}