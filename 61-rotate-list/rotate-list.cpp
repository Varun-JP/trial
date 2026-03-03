class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n =1;
        if (!head || !head->next) return head; //imp
        ListNode* new_tail= head ;
        ListNode* tail = head ;
        ListNode* new_head = head;
        while(tail -> next ){ //as long as it exists
            n++;
            tail = tail -> next; 
        }
        k = k% n ;
        if (k==0) return head;

        for(int i=1; i< n-k ;i++){
            new_tail = new_tail-> next;  //  till k-1 element 
        }
        new_head = new_tail -> next; // next of the new tail to wrap around
        tail-> next = head; //wrap around since orignal is breaking at 
        new_tail-> next = nullptr;
        return new_head;
    }
};