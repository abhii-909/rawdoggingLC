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
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> listvalues;

        while(temp != nullptr)
        {
            listvalues.push_back(temp->val);
            temp = temp->next;
        }
        sort(listvalues.begin(), listvalues.end());
        temp = head;
        int i =- 1;
        while(temp != nullptr)
        {
            i++;
            temp->val = listvalues[i];
            temp = temp->next;
        }
        return head;
    }
};