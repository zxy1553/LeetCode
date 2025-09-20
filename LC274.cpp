#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
    public:
        int hIndex(vector<int>& citations) {
            int h=0,citation=0;
            sort(citations.begin(), citations.end(), greater<int>());
            for(int i=0;i<citations.size();i++){
                citation=citations[i];
                if(i+1>=citations[i]){
                    h=citations[i];
                    break;
                }else{
                    h=i+1;
                }
                
                
            }
            return h;
        }
    };


int main() {
    Solution sol;
    
    vector<int> nums3={100};
    vector<int> nums1 = {3,0,6,1,5};
    vector<int> nums2 = {1,3,1};
    cout << sol.hIndex(nums1) << endl;
    cout << sol.hIndex(nums2) << endl;
    cout << sol.hIndex(nums3) << endl;


    return 0;
}