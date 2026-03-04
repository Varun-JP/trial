
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev;
        ListNode* curr = head;
        ListNode* newStart;
        ListNode* prevEnd = nullptr;
        ListNode* kth;
        ListNode* node;
        while(curr!=nullptr){
            kth = curr;
            for(int i=1; i< k && kth!=nullptr ; i++){
                kth = kth->next;
            }
            if(kth == 0) break;
            newStart = kth->next;
            prev = newStart;
            node = curr;
            while(node!= newStart){
                ListNode* temp = node->next;
                node->next = prev;
                prev = node;
                node = temp;
            }
            if(prevEnd == nullptr){
                head = kth;
            }
            else{
                prevEnd->next = kth;
            }
            prevEnd = curr;
            curr = newStart;

        }
        return head;
    }
};