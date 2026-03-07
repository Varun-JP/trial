class Node {
public:
    int key, value;
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
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int cap;

    inline void removeNode(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }

    inline void insertAfterHead(Node* node) {
        Node* first = head->next;

        node->next = first;
        node->prev = head;

        first->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end()) return -1;

        Node* node = it->second;

        removeNode(node);
        insertAfterHead(node);

        return node->value;
    }

    void put(int key, int value) {

        auto it = mp.find(key);

        if(it != mp.end()){
            Node* node = it->second;
            node->value = value;

            removeNode(node);
            insertAfterHead(node);
            return;
        }

        if(mp.size() == cap){
            Node* lru = tail->prev;

            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* node = new Node(key,value);
        insertAfterHead(node);
        mp[key] = node;
    }
};