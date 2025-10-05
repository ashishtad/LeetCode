
class LFUCache {
public:
    class Node {
        public:
        int key;
        int value;
        Node *prev;
        Node *next;
        
        Node (){}
        Node (int k, int val):key(k), value(val) {
            prev = nullptr;
            next = nullptr;
        }
    };
    /* Tracks the least frequency */
    int leastFreq;
    int cap;
    /* LFU map holds <key, <Node*,freq> , freq here is current frequency of key*/
    unordered_map<int, pair<Node*,int>> mLFUMap;
    /* Freq map to hold freq and list (head , tail) which is freq and list of nodes of that freq */
    unordered_map<int, pair<Node*, Node*>> freqMap;
    LFUCache(int capacity) {
        this->cap = capacity;
        this->leastFreq = -1;
    }
    
    int get(int key) {
        int result = -1;
        if (mLFUMap.count(key)) {
            auto &[node, freq] = mLFUMap[key];
            result = node->value;
            /* Update the freq list as we accessed the key */
            updateFreqList(node, freq);
            /* Freqlist updated with freq+1. Now update LFUmap to new freq */
            mLFUMap[key] = std::make_pair(node, freq+1);
        }
        return result;
    }
    
    void put(int key, int value) {
        
        if (mLFUMap.count(key)) {
            /* Key already exists. Update it */
            auto &[curNode, freq] = mLFUMap[key];
            /* Update curNode value */
            curNode->value = value;
            updateFreqList(curNode, freq);
            /* Freqlist updated with freq+1. Now update LFUmap to new freq */
            mLFUMap[key] = std::make_pair(curNode, freq+1);

        } else {
            /* New key insertion */
            if (mLFUMap.size() == this->cap) {
                
                /* Delete the least frequently used key */
                int delkey = removeLeastUsedKey(this->leastFreq);
                /* Remove LFU map */
                mLFUMap.erase(delkey);
            }
            Node *newNode = new Node(key,value);
            mLFUMap.insert(std::make_pair(key, make_pair(newNode,1)));
            addToFreqList(newNode, 1);
            /* New node inserted to freq:1 list , update leastFreq */
            this->leastFreq = 1;
        }
       
    }
    void addToFreqList(Node *newNode,int freq) {
        /* List empty for this freq , create list */
        if (0 == freqMap.count(freq)) {
            Node *head = new Node(-1, -1);
            Node *tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            /* Insert in freq map */
            freqMap[freq] = std::make_pair(head, tail);
        } 
        auto &[head, tail] = freqMap[freq];
        Node *first = head->next;
        head ->next = newNode;
        newNode->prev = head;
        newNode->next = first;
        first->prev = newNode;
    }

    void updateFreqList(Node *node, int freq) {
        /* Delete the node from cur freq list and then add to next freq+1 list */
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        int newFreq = freq+1;
        addToFreqList(node, newFreq);
        /* Check after deletion if the list is empty. If so update leastfreq if applicable */
        auto it = freqMap.find(freq);
        if (it != freqMap.end()) {
            Node *head = it->second.first;
            Node *tail = it->second.second;
            if (head->next == tail) {
                /* List is empty now. Update leastFreq */
                cleanupFreqList(freq);
                if (this->leastFreq == freq) {
                    /* Recalculate least frequency */
                    if (!freqMap.empty()) {
                        this->leastFreq = std::min_element(freqMap.begin(), freqMap.end(),
                                            [](auto &a, auto &b) { return a.first < b.first;})->first;
                    } else this->leastFreq = -1;
                }
            }
        }
    }
    /* Takes care of cleanup/erase of freq list if it's empty */
    void cleanupFreqList(int freq) {
        auto &[head, tail] = freqMap[freq];
        /* Freq list is empty , delete the head and tail pointers */
        if (head->next == tail) {
            delete head;
            delete tail;
            head = nullptr;
            tail = nullptr;
            freqMap.erase(freq);
        }
    }
    /* Return the key which is removed */
    int removeLeastUsedKey(int leastfreq) {
        /* Last element of least freq list */
        auto &[head,tail] = freqMap[leastfreq];
        Node *delNode = tail->prev;
        int delkey = -1;
        if (delNode !=head) {
            delNode->prev->next = tail;
            tail->prev = delNode->prev;
            delkey = delNode->key;
            delete delNode;
            delNode = nullptr;
        }
        /* We have deleted a node now. Check if leastFreq list is empty */
        auto it = freqMap.find(leastfreq);
        if (it != freqMap.end()) {
            Node *head = it->second.first;
            Node *tail = it->second.second;
            /* Check if freq list is empty now */
            if (head->next == tail) {
                cleanupFreqList(leastFreq);
                /* Recalculate least frequency */
                if (!freqMap.empty()) {
                    this->leastFreq = std::min_element(freqMap.begin(), freqMap.end(),
                                      [](auto &a, auto &b) { return a.first < b.first;})->first;
                } else this->leastFreq = -1;

            } 
        }
        return delkey;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */