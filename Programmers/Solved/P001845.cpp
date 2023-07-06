#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> MP;
    for(auto a : nums) {
        MP[a]++;
    }
    if(MP.size() >= nums.size()/2) answer = nums.size()/2;
    else answer = MP.size();
    
    return answer;
}