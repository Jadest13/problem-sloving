#include <iostream>
#include <algorithm>

using namespace std;

string subject;
double score;
string grade;
double sum;
double R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i = 1; i <= 20; i++) {
    cin >> subject >> score >> grade;
    if(grade == "P") continue;
    double tmp;
    if(grade[0] == 'A') tmp = 4;
    if(grade[0] == 'B') tmp = 3;
    if(grade[0] == 'C') tmp = 2;
    if(grade[0] == 'D') tmp = 1;

    if(grade[1] == '+') tmp += 0.5;
    if(grade[1] == '0') tmp += 0.0;
    if(grade[0] == 'F') tmp = 0;

    sum += score;
    R += tmp * score;
  }

  cout << fixed;
  cout.precision(4);
  cout << ((R==0)?0:(R/sum));

  return 0;
}