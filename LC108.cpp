#include <bits/stdc++.h>

using namespace std;



struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int n = nums.size();
        if(n==0){
            return nullptr;
        }
        // if (n == 1)
        // {
        //     TreeNode* node = new TreeNode(nums[0]); 
        //     return node;
        // }
        // if(n==2){
        //     TreeNode* node = new TreeNode(nums[1]);
        //     node->left = new TreeNode(nums[0]);
        //     return node;
        // }
        int index = n / 2;
        TreeNode *root = new TreeNode(nums[index]);
        vector<int> leftPart(nums.begin(), nums.begin() + index);
        vector<int> rightPart(nums.begin() + index+1, nums.end());
        root->left = sortedArrayToBST(leftPart);
        root->right = sortedArrayToBST(rightPart);
        return root;
    }
};


int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution solution;
    solution.sortedArrayToBST(nums);
}