/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*, Node*> mp;

        // sari dummy nodes bana lete hai pehle
        while(temp != NULL){
            Node* nn = new Node(temp -> val);
            mp[temp] = nn;
            temp = temp -> next;
        }
        temp = head;

        // ab pointers lagate hai
        while(temp != NULL){
            Node* copy = mp[temp];
            copy->next = mp[temp->next];
            copy->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};