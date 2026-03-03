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
            for (int i = 1; i < k && kth != nullptr; i++) {
                 kth = kth->next;
            }
            if (kth == nullptr) break;
            ListNode* nextGroupStart = kth->next;
            ListNode* prev = nextGroupStart;
            ListNode* node = curr;

            while (node != nextGroupStart) {
                 ListNode* temp = node->next;
                node->next = prev;
                prev = node;
                 node = temp;
                }  
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