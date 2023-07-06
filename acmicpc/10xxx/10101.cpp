#include <iostream>
#include <algorithm>

using namespace std;

int A, B, C;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B >> C;
  
  if(A+B+C == 180) {
    if(A == B || B == C || A == C) {
      if(A == 60) {
        cout << "Equilateral";
      } else {
        cout << "Isosceles";
      }
    } else {
      cout << "Scalene";
    }
  } else {
    cout << "Error";
  }

  return 0;
}