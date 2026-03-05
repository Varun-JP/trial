//Floyd’s cycle-finding (tortoise and hare):
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head ) return false;
        ListNode* slow = head;
        ListNode* fast = head;


        while(fast && fast->next){
            
            slow = slow-> next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};

//alternate 
/*class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        ListNode* curr = head;

        while(curr) {
            if(visited.count(curr)) return true;
            visited.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};*/