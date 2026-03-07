struct Node;

struct NodePtr {
    uint16_t ptr = 0;
    constexpr NodePtr() = default;
    template <typename T>
    constexpr NodePtr(T x) : ptr{(uint16_t)x} {}
    Node* operator->();
    operator bool() const { return ptr; }
};


struct Node {
    uint16_t key = 0, value = 0;
    NodePtr prev = 0, next = 0;
    Node() = default;
    Node(uint16_t key, uint16_t value) : key{key}, value{value} {};
};
alignas(64) constinit Node node_alloc[3000]{};

Node* NodePtr::operator->() {
    return &node_alloc[ptr - 1];
}

constinit NodePtr fast_map[(int)1e4 + 1]{};
struct List {
    NodePtr head = 0, tail = 0;

    NodePtr& next_prev(NodePtr node) {
        return node->next ? node->next->prev : tail;
    }

    NodePtr& prev_next(NodePtr node) {
        return node->prev ? node->prev->next : head;
    }

    void put(NodePtr node) {
        node->next = head;
        next_prev(node) = node;
        head = node;
    }

    NodePtr pop(NodePtr node = 0) {
        node = node ? node : tail;

        next_prev(node) = node->prev;
        prev_next(node) = node->next;

        node->prev = node->next = 0;
        return node;
    }

    ~List() {
        while (head) {
            NodePtr next = head->next;
            fast_map[head->key] = 0;
            head = next;
        }
    }
};

uint16_t node_pos = 0;
NodePtr new_node(uint16_t key, uint16_t value) {
    Node& node = node_alloc[node_pos++];
    node = Node(key, value);
    return node_pos;
}

class LRUCache {
    uint16_t capacity_ = 0;
    List cache_;

    NodePtr tryGet(uint16_t key) {
        if (auto it = fast_map[key]; it != 0) {
            cache_.put(cache_.pop(it));
            return it;
        }
        return 0;
    }

public:
    LRUCache(int capacity) : capacity_{(uint16_t)capacity} { node_pos = 0; }
    
    int get(int key) {
        if (NodePtr node = tryGet(key); node != 0) {
            return node->value;
        }
        return -1;
    }

    
    void put(int key, int value) {
        if (NodePtr node = tryGet(key); node != 0) {
            node->value = value;
            return;
        }

        NodePtr node = 0;
        if (capacity_ == 0) {
            node = cache_.pop();
            fast_map[node->key] = 0;
            node->key = key;
            node->value = value;
        } else {
            --capacity_;
            node = new_node(key, value);
        }
        fast_map[key] = node;
        cache_.put(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * uint16_t param_1 = obj->get(key);
 * obj->put(key,value);
 */