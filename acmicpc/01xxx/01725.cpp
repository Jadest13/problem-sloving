#include <iostream>
#include <stack>

using namespace std;

int N;
int A[100002];
int R;
stack<int> S;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  S.push(0);
  for(int i = 1; i <= N+1; i++) {
    while(!S.empty() && A[S.top()] > A[i]) {
      int a = S.top();
      S.pop();
      R = max(R, (i-S.top()-1)*A[a]);
    }
    S.push(i);
  }

  cout << R;
}