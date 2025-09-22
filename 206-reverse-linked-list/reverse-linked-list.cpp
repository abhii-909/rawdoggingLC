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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = NULL;
        ListNode* curr = head;
        ListNode* Next = NULL;

        while(curr != NULL){
            Next = curr -> next;
            curr->next = dummy;

            dummy  = curr;
            curr = Next;
        }
        return dummy;
    }
};