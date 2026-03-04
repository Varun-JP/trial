class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new  ListNode(-1);
        ListNode* curr = dummy;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        while(curr1 != NULL && curr2 != NULL){
            if(curr1-> val < curr2 -> val){
                curr-> next = curr1;
                curr1 = curr1->next;
            }
            else{
                curr-> next = curr2;
                curr2 = curr2->next;
            }
            curr = curr-> next;
        }
        if(curr1 != NULL){
            curr-> next = curr1;
        }
        else{
            curr-> next = curr2;
        }
        return dummy->next;
    }
};