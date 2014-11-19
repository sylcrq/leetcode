#ifndef _LEETCODE_LRU_CACHE_H_
#define _LEETCODE_LRU_CACHE_H_

#include <iostream>
#include <map>

class LRUCache
{
public:
    LRUCache(int capacity);
    ~LRUCache();

    int get(int key); 
    void set(int key, int value); 

    // For DEBUG
    void print_list();

private:
    // 双向链表
    struct ListNode 
    {
        int key;
        int value;
        ListNode* next;
        ListNode* prev;

        ListNode(int k, int v) : key(k), value(v), next(NULL), prev(NULL) {}
    };

    ListNode* list_push_front(int key, int value);
    void list_pop_back();
    void list_move_front(ListNode* node);

    ListNode* head_;
    ListNode* tail_;
    int capacity_;
    int size_;

    std::map<int, ListNode*> kv_map_;
};

#endif
