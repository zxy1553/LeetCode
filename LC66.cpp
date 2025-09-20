#include<iostream>
#include<vector>

using namespace std;


class Solution{
    public:
    vector<int> plusOne(vector<int>& digits){
        int len = digits.size();
        int i=len-1;
        while(i>-1 && digits[i]==9){
            i--;
        }
        if(i==-1){
            vector<int> newDigits(len+1,0);
            newDigits[0]=1;
            return newDigits;
        }
        digits[i]++;
        
        if(i != len-1){
           while(++i<len){
            digits[i]=0;
           } 
        }
        return digits;
    }
};

int main(){
    Solution sol;
    vector<int> digits = {1,9,9,9,9,9,9,9,9,9,9,9,9,9};
    vector<int> res=sol.plusOne(digits);
    for(auto& num : res){
        cout<<num;
    }
}