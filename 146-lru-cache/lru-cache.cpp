//doubly LL
class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

//start
class LRUCache {
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int cap;

public:
    LRUCache(int capacity) { //constructor so has the same name as the class
        cap = capacity;
        head = new Node(-1, -1); //(key , value)
        tail = new Node(-1, -1);
        head->next = tail; //borders to avoid if nullptr used then we have 
        tail->prev = head; //parse again and again for finding LRU node
    } //aka dummy (sentinel) nodes.

    void removeNode(Node* node) {
        node->prev->next = node->next; //A <-> B <-> C to  A <-> C
        node->next->prev = node->prev;
    }

    void insertAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;
        Node* node = mp[key];
        removeNode(node);
        insertAfterHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            node->value = value;
            removeNode(node);
            insertAfterHead(node);
        } else {
            if (mp.size() == cap) {
                //only till the capcity then delete least recent 
                Node* lru = tail->prev;
                removeNode(lru);
                mp.erase(lru->key); //to erase that cleanly
                delete (lru);
            }
            Node* node = new Node(key, value);
            insertAfterHead(node);
            mp[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */