/* addNode：如果已存在该key的节点，则更新该节点的val，否则创建一个新的node添加到head，然后判断是否出现map.size() > capacity，如果超过则remove最后的节点。
 * moveToHead：使用get操作的时候将该节点移动到head的位置，
 * removeNode：移除某一处的node，使用map[key] 进行节点查找
 *
 *
 */

# include <unordered_map>

class LRUCache {
private:
    struct Node {
        int val;
        Node *prev, *next;

        Node(int val) {
            this->val = val;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity = 0;
    Node *head;
    Node *tail;
    std::unordered_map<int, Node *> cache;

    void addNode(int key, int val) {
        Node *newNode = new Node(val);
        cache[key] = newNode;
        newNode->next = head;
        newNode->prev = nullptr;
        head = newNode;
    }

    void moveToHead(Node *e) {
        e->prev->next = e->next;
        e->next->prev = e->prev;
        e->next = head;
        head = e;
        e->prev = nullptr;
    }

    void removeNode() {
        Node *e = tail;
        tail = tail->prev;
        tail->prev = tail;
        delete e;
    }

public:
    LRUCache(int capacity) {
        head = tail = nullptr;
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            return cache[key]->val;
        } else return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->val = value;
        } else {
            addNode(key, value);

            if (cache.size() > capacity) {
                removeNode();
                Node *e = tail;
                tail->prev
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
