/*
 * Author: robot
 * Source : https://leetcode.cn/problems/lru-cache/
 */
#include <iostream>
#include <unordered_map>
using namespace std;

struct DLinkedNode {
    int key;
    int value;
    DLinkedNode* pre;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), pre(NULL), next(NULL) {}
    DLinkedNode(int key_, int value_) : key(key_), value(value_), pre(NULL), next(NULL) {}
};

// LRU 最近最少使用 访问（修改也算）过得会放到头部，默认尾部淘汰
// 结合LRU的特性，可以采用map+双向链表的方式实现
class LRUCache {
   private:
    unordered_map<int, DLinkedNode*> data;
    int capacity;
    int size;
    DLinkedNode* head;
    DLinkedNode* tail;

   public:
    LRUCache(int capacity) { 
        capacity = capacity;
        // 虚拟首位节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->pre = head;
        size = 0;
    }

    int get(int key) {
        if (data.find(key) == data.end()) {
            return -1;
        }
        DLinkedNode* node = data[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (data.find(key) == data.end()) {
            DLinkedNode* node = new DLinkedNode(key, value);
            data[key] = node;
            addToHead(node);
            size++;
            if (size > capacity) {
                // 从尾部删除
                DLinkedNode* removed = removeTail();
                data.erase(removed->key);
                size--;
            }
        } else {
            DLinkedNode* node = data[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    void removeNode(DLinkedNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void addToHead(DLinkedNode* node) {
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->pre;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */