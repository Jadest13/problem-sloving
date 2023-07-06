#include <bits/stdc++.h>

using namespace std;

int N, r, c;

int F(int n, int r, int c) {
	if(n == 1) return 1;
	int ret = 0;

	if(r < n/2 && c < n/2)
		return ret + F(n/2, r, c);
	ret += (n/2)*(n/2);
	if(r < n/2)
		return ret + F(n/2, r, c-n/2);
	ret += (n/2)*(n/2);
	if(c < n/2)
		return ret + F(n/2, r-n/2, c);
	ret += (n/2)*(n/2);
	return ret + F(n/2, r-n/2, c-n/2);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
	cin >> N >> r >> c;
	int bit = 1 << N;
	cout << F(bit, r, c) - 1;

  return 0;
}
