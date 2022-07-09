class LRUCache {
public:
    class Node {
        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        
        Node (int _key, int _val) {
            key = _key;
            val = _val;
        }
    };
    
    int cap;
    unordered_map<int, Node*> mp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* node) {
        auto temp = head->next;
        head->next = node;
        node->next = temp;
        temp->prev = node;
        node->prev = head;
    }
    
    void deleteNode(Node* node) {
        auto temp_next = node->next;
        auto temp_prev = node->prev;
        temp_prev->next = temp_next;
        temp_next->prev = temp_prev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
            addNode(curr);
            mp[key] = head->next;
            return curr->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            auto curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }
        if(mp.size() == cap) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */