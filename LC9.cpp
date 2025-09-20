#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        int n = num.length() / 2;

        int i = 0;
        while (i < n) {
            if (num[i] != num[n - 1 - i]) {
                return false;
            }
            i++;
        }
        return true;
    }
};

class Solution2{
    public:
    bool isPalindrome(int x){
        if(x<0 || (x%10 == 0 && x!= 0)){
            return false;
        }

        int revertedNumber = 0;
        while(x>revertedNumber){
            revertedNumber = revertedNumber * 10 + x%10;
            x/=10;
        }
        return x==revertedNumber || x == revertedNumber/10;
    }
};

int main(){
    Solution sol;

    int x=10;
    cout<<sol.isPalindrome(x);
}