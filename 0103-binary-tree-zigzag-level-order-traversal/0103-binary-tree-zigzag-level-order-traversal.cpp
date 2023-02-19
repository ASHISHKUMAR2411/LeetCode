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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root == NULL){
            return answer;
        }
        queue<TreeNode*> que;
        que.push(root);
        int flag = 0;
        while(!(que.empty())){
            int size = que.size();
            vector<int> ans;
            for(int i = 0; i < size; i++){
                TreeNode *top = que.front();
                que.pop();
                if(top->left){
                    que.push(top->left);
                }
                if(top->right){
                    que.push(top->right);
                }
                ans.push_back(top->val);
            }
            if(flag == 0){
                answer.push_back(ans);
                flag = 1;
            }
            else{
                reverse(ans.begin(), ans.end());
                answer.push_back(ans);
                flag = 0;
            }
        }
        return answer;
    }
};