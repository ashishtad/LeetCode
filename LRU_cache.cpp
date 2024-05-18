#include <unordered_map>
using namespace std;

class Node {

    int key;
    int value;
    
    public:
    Node *prev;
    Node *next;
    Node(){}
    Node( int key, int val) {
        this->key = key;
        this->value = val;
        prev = nullptr;
        next = nullptr;
    }
    int getVal(){
        return this->value;
    }
    int getKey(){
        return this->key;
    }
};
/*
  Doubly linked list to maintain the LRU cache.
  Doubly linke list is used to so as to perform deltion
  and addition of nodes efficiently when node is given as input. 
  Otherwise in singly LL we need to traverse to concerned for deletion. 
  head and tail are for references actual LRU list is inserted in between 
  head and tail.
  List is maintained such that first element that is element after head
  is the most recently used and the last node that is the node before tail
  is the least recently used.
*/
Node *head = new Node(-1,-1);
Node *tail = new Node(-1,-1);
/* LRU map to access the key quickly in O(1) time */
unordered_map<int,Node*> LRU_map;

class LRUCache {
    int max_size;
public:
    LRUCache(int capacity) {
        this->max_size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode( Node *node){
        if(node){
            Node *prev_node = node->prev;
            Node *next_node = node->next;
            prev_node->next = next_node;
            next_node->prev = prev_node;
            node->next = nullptr;
            node->prev = nullptr;
            /* Dont delete node here -
              can cause undefined behaviour or SIGSEGV while
              accessing as the node ref is present in LRU_map */
        }
    }

    /* Add the node at the beginning of list*/
    void addNode( Node *node){
        if(node){
           
            Node *next_node = head->next;
            head->next = node;
            node->prev = head;
            node->next = next_node;
            next_node->prev = node;
            /* Insert into map */
            LRU_map.insert(make_pair(node->getKey(),node));
        }
    }
    int get(int key) {

        int result = -1;
        /* If node is found for the key. 
            Extract the value , delete it as it is now touched while extracting the value.
            Add it again as it's a accessed.
        */
        if(LRU_map.find(key) != LRU_map.end()){
            Node *node_found = LRU_map[key];
            result = node_found->getVal();
            deleteNode(node_found);
            addNode(node_found);
        }
        return result;
        
    }
    
    void put(int key, int value) {
        Node *node = nullptr;
        /* If key already exists*/
        if(LRU_map.find(key) != LRU_map.end()){

            node = LRU_map[key];
            LRU_map.erase(key);
            deleteNode(node);
            
        } else {
            node = new Node(key,value);
        }
        /* Check the size of cache */
        if( LRU_map.size() == max_size){
            /* Remove the least recent used node*/
            LRU_map.erase(tail->prev->getKey());
            deleteNode(tail->prev);
        }
        addNode(node);
    }
};
