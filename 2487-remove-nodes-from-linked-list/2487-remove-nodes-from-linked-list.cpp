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
    ListNode* reverse_list(ListNode* head){
        ListNode *prev = NULL, *temp = head, *next = NULL;
        while(temp){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if(head == NULL) return NULL;
        head = reverse_list(head);
        int maxi = INT_MIN;
        ListNode *prev = NULL, *temp = head;
        while(temp){
            if(temp->val < maxi){
                prev->next = temp->next;
                temp = temp->next;
            }
            else{ 
                maxi = max(maxi, temp->val);
                prev = temp;
                temp = temp->next;
            }
        }
        head = reverse_list(head);
        return head;
        
    }
};