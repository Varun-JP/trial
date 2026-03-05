
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * fast = head;
        ListNode * slow = head;
        ListNode* curr = head;
        while(fast && fast->next){
            fast= fast->next->next;
            slow= slow->next;
            if(fast == slow){
                while(curr!= slow){
                    curr = curr->next;
                    slow = slow->next;
                }
                return curr;
            }
        }
        return NULL;
    }
};