/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st, s;
        int maxi = INT_MIN;
        while(head){
            st.push(head->val);
            head = head->next;
        }
        int n = (st.size())/2;
        while(n){
            s.push(st.top());
            st.pop();
            n--;
        }
        while(!(st.empty()) and !(s.empty())){
            int sum = st.top() + s.top();
            maxi = max(maxi, sum);
            st.pop();
            s.pop();
        }
        return maxi;
    }
};