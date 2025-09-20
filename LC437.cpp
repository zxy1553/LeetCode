#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int pathSum(TreeNode *root, int targetSum) {
    int ans = 0;
    //前缀和为0的有1个
    unordered_map<long long, int> cnt{{0,1}};
    auto dfs = [&](this auto&& dfs, TreeNode* node, long long s){
        if(node == nullptr){
            return;
        }
        s += node->val;

        ans += cnt[s-targetSum];

        cnt[s]++;
        dfs(node->left,s);
        dfs(node->right,s);
        cnt[s]--;
    };

    dfs(root,0);

    return ans;

  }
};