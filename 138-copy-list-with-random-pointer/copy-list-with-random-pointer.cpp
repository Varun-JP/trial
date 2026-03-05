/*
    Definition for a Node.
    class Node {
    public:
        int val;
        Node* next;
        Node* random;
        
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
        if (!head) return NULL;

        Node* curr = head;

        // =========================
        // PHASE 1: INTERLEAVE COPIES
        // =========================
        // Goal:
        // Transform:
        // A -> B -> C
        //
        // Into:
        // A -> A' -> B -> B' -> C -> C'
        //
        // Invariant after this phase:
        // For every original node X:
        //      X->next is its clone
        //      X->next->next is the next original node

        while (curr) {
            Node* copy = new Node(curr->val);   // Create clone of current node

            copy->next = curr->next;            // Clone points to next original
            curr->next = copy;                  // Original now points to its clone

            curr = copy->next;                  // Move to next original (skip clone)
        }

        // Head of cloned list is right after original head
        Node* copyHead = head->next;

        // =========================
        // PHASE 2: ASSIGN RANDOM POINTERS
        // =========================
        // For any original node X:
        //
        // If X.random = Y
        // Then X'.random should be Y'
        //
        // Since Y' is right after Y:
        // Y' = Y->next
        //
        // Therefore:
        // X->next->random = X->random->next

        curr = head;

        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            } else {
                curr->next->random = NULL;
            }

            curr = curr->next->next;  // Jump to next original node
        }

        // =========================
        // PHASE 3: SEPARATE THE TWO LISTS
        // =========================
        // Current structure:
        // A -> A' -> B -> B' -> C -> C'
        //
        // We want:
        // Original: A -> B -> C
        // Clone:    A' -> B' -> C'
        //
        // Strategy:
        // - Restore original next pointers
        // - Fix clone next pointers by skipping originals

        curr = head;

        while (curr) {
            Node* copy = curr->next;      // Clone node

            curr->next = copy->next;      // Restore original link

            if (copy->next) {
                copy->next = copy->next->next;  // Link clone to next clone
            } else {
                copy->next = NULL;
            }

            curr = curr->next;            // Move to next original
        }

        return copyHead;
    }
};