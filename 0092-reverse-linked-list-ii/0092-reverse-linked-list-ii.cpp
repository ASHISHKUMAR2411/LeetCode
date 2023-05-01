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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        if(head == NULL) return head;
        // ListNode *l = NULL, *r = NULL;
        ListNode *temp = head, *prev1 = NULL, *prev2 = NULL;
        int count = 1;
        while(temp){
            if(count == left - 1){
                prev1 = temp;
            }
            if(count == right){
                prev2 = temp;
                break;
            }
            count++;
            temp = temp->next;
        }
        
        ListNode *next = prev2->next, *head1 = NULL;
        prev2->next = NULL;
        if(prev1 == NULL) head1 = head;
        else head1 = prev1->next;
        
        // while(head1->next){
        //     cout << head1->val << " ";
        //     head1 = head1->next;
        // }
        head1 = reverse_list(head1);
        if(prev1 == NULL) head = head1;
        else prev1->next = head1;
        while(head1->next){
            // cout << head1->val << " ";
            head1 = head1->next;
        }
        // cout << head1->val << endl;
        head1->next = next;
        return head;
    }
};