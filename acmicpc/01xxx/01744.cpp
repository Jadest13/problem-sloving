#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> V1, V2;
int one, zero;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if(a < 0) V1.push_back(a);
    if(a > 0) {
      if(a==1) one++;
      else V2.push_back(a);
    }
    if(a == 0) zero = 1;
  }
  sort(V1.begin(), V1.end());
  sort(V2.rbegin(), V2.rend());

  for(int i = 0; i < V1.size()/2; i++) {
    R += (V1[i*2]*V1[i*2+1]);
  }
  if(V1.size()%2) {
    if(!zero)
      R += V1[V1.size()-1];
  }

  for(int i = 0; i < V2.size()/2; i++) {
    R += (V2[i*2]*V2[i*2+1]);
  }
  if(V2.size()%2) R += V2[V2.size()-1];
  R += one;

  cout << R;

  return 0;
}