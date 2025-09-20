#include<iostream>

using namespace std;

class Solution{

    public:
    int hammingWeight(int n){
        int ans=0;
        for(int i=0; i<32; ++i){
            if((n>>i & 1)==1) ans++;
        }
        return ans;
    }
};

int main(){
    int n=11;
    Solution sol;
    cout<<sol.hammingWeight(n);
}