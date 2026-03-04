class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head; 
         // empty list or single node, nothing to reverse
        
        ListNode* curr = head;             
        // current pointer to iterate through the list
        ListNode* prevGroupEnd = nullptr;  
        // tail of the previous reversed group
        
        while (curr != nullptr){
            ListNode* kth = curr; 
            // find the k-th node from current group start
            for (int i = 1; i < k && kth != nullptr; i++) {
                 kth = kth->next;
            }
            if (kth == nullptr) break;    // less than k nodes left, leave as is
            
            ListNode* nextGroupStart = kth->next;  // first node of next group
            ListNode* prev = nextGroupStart;      
             // prev for reverse: points to node after current group
            ListNode* node = curr;                 // start reversing from curr
            
            // reverse nodes in the current group
            while (node != nextGroupStart) {
                ListNode* temp = node->next;
                node->next = prev;
                prev = node;
                node = temp;
            }  
            
            // connect previous group to current reversed group
            if (prevGroupEnd == nullptr)
                 head = kth;           
                  // first group: update head to new head (kth node)
            else
                 prevGroupEnd->next = kth;   
                 // subsequent groups: attach previous tail to new head
            
            prevGroupEnd = curr;          
            // update prevGroupEnd to tail of this reversed group
            curr = nextGroupStart;        // move curr to the start of next group
        }
        
        return head;
    }
};