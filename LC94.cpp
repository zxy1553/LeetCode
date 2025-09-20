
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

class Solution {
    private:
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        inorderTraversal(root->left);
        res.emplace_back(root->val);
        inorderTraversal(root->right);
        return res;
    }

};


