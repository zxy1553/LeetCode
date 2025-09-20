#include<iostream>
#include<vector>
#include<queue>


using namespace std;


class Solution{

    public:
    int quickselect(vector<int>& nums, int l, int r, int k){
        if(l==r){
            return nums[k];
        }
        int partition = nums[l], i=l-1, j=r+1;
        while(i<j){
            do i++; while(nums[i]<partition);
            do j--; while(nums[j]>partition);
            if(i<j){
                swap(nums[i],nums[j]);
            }
        }
        if(k<=j) return quickselect(nums,l,j,k);
        else return quickselect(nums, j+1, r, k); 
    }

    int findKthLargest(vector<int> &nums, int k){
        int n = nums.size();
        return quickselect(nums, 0, n-1, n-k);
    }

};

class Solution2{
    public:
    int findKthLargest(vector<int>& nums, int k){
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto& num: nums){
            minHeap.push(num);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
}


