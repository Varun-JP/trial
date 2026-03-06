class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int cap;

    // Helper: Removes a node from its current position in the DLL
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Helper: Adds a node right after the dummy head (Most Recently Used position)
    void insertAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1); // Sentinel/Dummy head
        tail = new Node(-1, -1); // Sentinel/Dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!mp.count(key)) {
            return -1;
        }

        Node* node = mp[key];
        removeNode(node);      // Take it out from its current spot
        insertAfterHead(node); // Move it to the front (MRU)
        return node->value;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            // Update existing key
            Node* node = mp[key];
            node->value = value;
            removeNode(node);
            insertAfterHead(node);
        } else {
            // New key
            if (mp.size() == cap) {
                // Evict Least Recently Used (node before tail)
                Node* lru = tail->prev;
                mp.erase(lru->key);
                removeNode(lru);
                delete lru; // Free memory
            }
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};