

#include <algorithm>
#include <cstddef>
#include <ios>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    private:
    int Height(TreeNode* root, int& ans){
        if(!root) return 0;
        int highL=Height(root->left,ans),highR = Height(root->right,ans);
        ans = max(ans,highL+highR);
        return max(highL,highR)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        Height(root, ans);
        return ans;
    }
};

TreeNode* buildTree(const vector<int>& vals){
    if(vals.empty() || vals[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i=1;
    while (!q.empty() && i<(int)vals.size()) {
        TreeNode* cur = q.front(); q.pop();
        if(i<vals.size() && vals[i]!=-1){
            cur->left = new TreeNode(vals[i]);
            q.push(cur->left);
        }
        i++;
        if(i<vals.size() && vals[i] != -1){
            cur->right = new TreeNode(vals[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vals(n);
    for(int i=0; i<n; ++i) cin>>vals[i];

    TreeNode* root = buildTree(vals);

    Solution sol;
    cout << sol.diameterOfBinaryTree(root);

}