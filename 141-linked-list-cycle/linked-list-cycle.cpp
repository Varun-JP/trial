//Floyd’s cycle-finding (tortoise and hare):
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head ) return false;
        ListNode* slow = head;
        ListNode* fast = head->next; //both can be heads at the start but  

        //in this loop you have to keep if slow == fast below the slow and fast otherwise it would hit at the first try and fail directly 
        while(fast!= NULL && fast->next !=NULL){
            if(slow == fast) return true;
            slow = slow-> next;
            fast = fast->next->next;
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