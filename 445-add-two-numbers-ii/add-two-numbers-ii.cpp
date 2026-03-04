class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* prev1= nullptr ;
        ListNode* prev2= nullptr ;
        ListNode* node;
        ListNode* result= nullptr;
        int carry=0;

        while(curr1!= nullptr ){
            ListNode* temp = curr1-> next;
            curr1->next = prev1;
            prev1 = curr1;
            curr1 = temp;
        }
        while(curr2!= nullptr ){
            ListNode* temp = curr2-> next;
            curr2->next = prev2;
            prev2 = curr2;
            curr2 = temp;
        }
        curr1 = prev1;
        curr2 = prev2;
        while(curr1 || curr2 || carry){
            int val1 = (curr1 !=nullptr)? curr1->val : 0;
            int val2 = (curr2 !=nullptr)? curr2->val : 0;
            int sum = val1+val2 +carry;
            int new_val = sum%10;

            node = new ListNode(new_val); // 17 .  7 goes in heere
            node->next = result; //1 here the new should point to the old
            result = node; //reult pointing to old node
            carry = sum/10;
            if(curr1) curr1 = curr1->next;
            if(curr2) curr2 = curr2->next;
        }
            while(result && result ->val ==0 && result->next){
                result = result->next;
            }
        return result;
    }
};

