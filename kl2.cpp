#include <iostream>

using namespace std;

typedef long long ll;

class Solution{
    public:
    ll findMaxONesNumber(ll l, ll r){
        int maxOnes = __builtin_popcountll(l);
        ll result = 1;
        
        int oneR = __builtin_popcountll(r);
        if(oneR > maxOnes){
            maxOnes = oneR;
            return r;
        }
        

        for(long long x=1; x<=r; x = (x<<1) + 1){
            if(x < l) continue;
            int ones = __builtin_popcountll(x);
            if(ones > maxOnes){
                maxOnes = ones;
                result = x;
            }
        }
        return result;

    }

    private:
    int countOnes(int n){
        int count = 0;
        while(n>0){
            count += n & 1;
            n>>=1;
        }
        return count;
    }
};

int main() {
    int  n;
    cin >>n;
    Solution sol;
    for(int i=0; i<n; ++i){
        int left,right;
        cin >>left >> right;
        cout << sol.findMaxONesNumber(left, right)<<"\n";
    }
}
// 64 位输出请用 printf("%lld")