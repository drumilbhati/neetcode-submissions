class Node {
public:
    int k, v;
    Node* prev;
    Node* next;

    Node(int key, int val) {
        this->k = key;
        this->v = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        this->cap = capacity;
        this->head = nullptr;
        this->tail = nullptr;
    }
    
    int get(int key) {
        if (mp.count(key)) {
            Node* node = mp[key];
            remove(node);
            move_back(node);
            return node->v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            node->v = value;
            remove(node);
            move_back(node);
            return;
        }

        if (this->mp.size() == this->cap) {
            evict();
        }

        Node* node = new Node(key, value);
        mp[key] = node;
        move_back(node);
    }

private:
    void remove(Node* node) {
        if (node->prev) node->prev->next = node->next;
        else head = node->next;     // node was head

        if (node->next) node->next->prev = node->prev;
        else tail = node->prev;     // node was tail

        node->prev = nullptr;
        node->next = nullptr;
    }

    void move_back(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
            return;
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    void evict() {
        if (head == nullptr) return;
        Node* oldHead = head;
        mp.erase(oldHead->k);

        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete oldHead;
    }
};
