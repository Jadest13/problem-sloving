#include <iostream>
#include <algorithm>

using namespace std;

string A, B;
char o;
string R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> o >> B;
  if(o == '+') {
    if(A.length() > B.length()) R = A;
    else R = B;
    R[max(A.length(), B.length()) - min(A.length(), B.length())]++;
  } else {
    R.push_back('1');
    for(int i = 0; i < A.length() + B.length() - 2; i++) {
      R.push_back('0');
    }
  }

  cout << R;

  return 0;
}