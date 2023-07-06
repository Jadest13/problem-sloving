#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long l = 0, r = 1e18;
    while(l < r) {
        long long m = (l+r)>>1;
        long long t = 0;
        for(auto a : times) {
            t += m / a;
        }
        if(t >= n) r = m;
        else l = m+1;
    }
    answer = l;
    return answer;
}