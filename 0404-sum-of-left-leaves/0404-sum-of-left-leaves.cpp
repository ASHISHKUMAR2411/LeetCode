/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isLeaf(TreeNode *node){
        if(node == NULL) return false;
        if(node->left == NULL and node->right == NULL) return true;
        else return false;
    }
    void solve(TreeNode *root, int& sum,bool flag){
        if(root == NULL){
            return;
        }
        if(flag and isLeaf(root)){
            sum += root->val;
        }
        solve(root->left, sum, true);
        solve(root->right, sum, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0; 
        solve(root, sum, false);
        return sum;
    }
};