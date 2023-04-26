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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        if(root == NULL) return answer;
        stack<TreeNode*> st;
        st.push(root);
        while(!(st.empty())){
            TreeNode *t = st.top();
            st.pop();
            answer.push_back(t->val);
            if(t->right) st.push(t->right);
            if(t->left) st.push(t->left);
        }
        return answer;
    }
};