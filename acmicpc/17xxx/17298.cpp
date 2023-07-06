#include <iostream>
#include <stack>

using namespace std;

stack<int> S;
int N;
int A[1000001], NGE[1000001];

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for(int i = N-1; i >= 0; i--) {
    while(!S.empty() && S.top() <= A[i]) {
      S.pop();
    }
    if(S.empty()) {
      NGE[i] = -1;
    } else {
      NGE[i] = S.top();
    }

    S.push(A[i]);
  }
  
  for(int i = 0; i < N; i++) {
    cout << NGE[i] << " ";
  }

  return 0;
}