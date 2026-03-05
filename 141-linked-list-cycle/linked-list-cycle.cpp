//Floyd’s cycle-finding (tortoise and hare):
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || head->next == nullptr ) return false;
        ListNode* curr = head;
        ListNode* slow = head;
        ListNode* fast = head->next;


        while(fast && fast->next){
            if(slow == fast) return true;
            slow = slow-> next;
            fast = fast->next->next;
        }
        return false;
    }
};