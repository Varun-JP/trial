/*
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        Node* copyhead;
        Node* copy  = copyhead;


        while(curr!= nullptr){
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        copyhead = head ?  head-> next :NULL;
        curr = head;
        while(curr){
            curr->next->random =  curr-> random? curr->random->next : NULL;
            curr= curr->next->next;
        }
        curr= head; 
        while(curr){
            Node* copy = curr->next;
            curr->next = copy->next; //B iscopied  //og is fixed by here but not copy
            copy->next = copy->next? copy->next->next : NULL;
            curr = curr->next;

            //ternary copy->next = copy->next ? copy->next->next : NULL;
        }

        return copyhead;
    }
};