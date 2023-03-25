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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode *t = head;
        while(t){
            st.push(t);
            t = t->next;
        }
        int size = st.size()/2;
        ListNode *temp = head;
        for(int i = 0; i < size; i++){
            ListNode *tt = st.top();
            st.pop();
            tt->next = temp->next;
            temp->next = tt;
            temp = temp->next->next;
        }
        temp->next = NULL;
        
        
    }
};