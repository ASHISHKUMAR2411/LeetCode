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
    void solve(TreeNode *root, vector<int> &arr){
        if(root == NULL){
            return;
        }
        solve(root->left, arr);
        arr.push_back(root->val);
        solve(root->right, arr);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // Your code here
        vector<int> arr;
        solve(root, arr);
        return arr;
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> arr = inorderTraversal(root);
        sort(arr.begin(), arr.end());
        int mini = INT_MAX;
        for(int i = 1; i < arr.size(); i++){
            mini = min(mini, arr[i] - arr[i-1]);
        }
        return mini;
    }
};