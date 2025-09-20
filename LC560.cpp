#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0, s=0;
        unordered_map<int, int> cnt;
        for(int x: nums){
            cnt[s]++;
            s += x;
            ans += cnt.count(s-k)?cnt[s-k]:0;
        }        
        return ans;
    }
};