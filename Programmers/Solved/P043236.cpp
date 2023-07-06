#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    vector<int> V;
    for(int i = 1; i < rocks.size(); i++) {
        V.push_back(rocks[i]-rocks[i-1]);
    }
    int l = 0, r = distance;
    
    while(l < r) {
        int m = (l+r)>>1;
        
        int len = 0;
        int ret = 0;
        for(auto a : V) {
            len += a;
            if(len <= m) {
                ret++;
            } else {
                len = 0;
            }
        }
        
        if(ret > n) r = m;
        else l = m+1;
    }
    answer = l;
    
    return answer;
}