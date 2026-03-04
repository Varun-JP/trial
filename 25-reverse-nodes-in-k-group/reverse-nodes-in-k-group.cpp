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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode* curr = head;
        ListNode* prevGroupEnd = nullptr;
        
        while (curr != nullptr){
            ListNode* kth = curr; 
            //start of the current group we are about to reverse
            for (int i = 1; i < k && kth != nullptr; i++) {
                 kth = kth->next;
            }
            if (kth == nullptr) break;
            //if nullptr then same as before so no change for that 
            ListNode* nextGroupStart = kth->next;
            ListNode* prev = nextGroupStart;
             //end point just as prev = nullptr for regular reverse
            ListNode* node = curr;
            //node goes from the first of the group to the last . 
            while (node != nextGroupStart) {
                ListNode* temp = node->next;
                node->next = prev;
                prev = node;
                node = temp;
                }  
            //we are reversing our very first group then this
            if (prevGroupEnd == nullptr)
                 head = kth;
            else
                 prevGroupEnd->next = kth;   

            prevGroupEnd = curr;
            curr = nextGroupStart;           
        }
        return head;
    }
};