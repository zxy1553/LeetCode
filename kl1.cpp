
#include <iostream>
#include <vector>


using namespace std;



struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {

    private:
    int max_h=0;
    vector<vector<int>> leaves;

    int height(TreeNode* root){
        if(!root) return 0;

        int left_h = height(root->left);
        int right_h = height(root->right);

        int h = max(left_h, right_h)+1;
        
        if(max_h<h){
            max_h = h;
            leaves.resize(h);
        }
        leaves[h-1].emplace_back(root->val);

        return h;

    }


public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return int整型vector
     */
    vector<int> pruneSequence(TreeNode* root) {
        int max_height = height(root);
        
        vector<int> res;
        for(int i=0; i<max_height; ++i){
            res.insert(res.begin(), leaves[i].begin(), leaves[i].end());
        }
        return res;
    }
};


int main(){
    TreeNode root(1);
    TreeNode node1(2);
    TreeNode node2(3);
    TreeNode node3(4);
    TreeNode node4(5);
    TreeNode node5(6);
    TreeNode node6(7);

    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
    node2.left = &node5;
    node3.right= &node6;

    Solution sol;
    auto res = sol.pruneSequence(&root);
    for(auto& i: res){
        cout<< i<<" ";
    }

}