#include <iostream>

using namespace std;

int N;
int A[201];
int a, v;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> a;
    A[a+100]++;
  }
  cin >> v;
  cout << A[v+100];
}