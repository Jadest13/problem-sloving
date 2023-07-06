#include <iostream>

using namespace std;

int X, N;
int a, b;

int main() {

  cin >> X >> N;
  for(int i = 0; i < N; i++) {
    cin >> a >> b;
    X -= a*b;
  }

  if(X) {
    cout << "No";
  } else {
    cout << "Yes";
  }

  return 0;
}