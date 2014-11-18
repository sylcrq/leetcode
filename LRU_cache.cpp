#include "LRU_cache.h"

using namespace std;

int LRUCache::get(int key)
{
    map<int, ListNode*>::iterator it = kv_map_.find(key);

    if(it == kv_map_.end())
        return -1;

    ListNode* node = it->second;
    // 更新节点到链表头!
    list_move_front(node);

    return node->value;
}

void LRUCache::set(int key, int value) 
{
    map<int, ListNode*>::iterator it = kv_map_.find(key);
    if(it == kv_map_.end())
    {
        if(size_ == capacity_)
        {
            // delete from list & hash map
            kv_map_.erase(tail_->key);
            list_pop_back();

            // insert into list & hash map
            ListNode* node = list_push_front(key, value);
            kv_map_.insert( pair<int, ListNode*>(key, node) );
        }
        else
        {
            // insert into list & hash map
            ListNode* node = list_push_front(key, value);
            kv_map_.insert( pair<int, ListNode*>(key, node) );
        
            size_++;
        }
    }
    else
    {
        ListNode* node = it->second;
        // update value
        node->value = value;

        // move to list head
        list_move_front(node);
    }
}

LRUCache::ListNode* LRUCache::list_push_front(int key, int value)
{
    ListNode* node = new ListNode(key, value);
    if(head_ == NULL)
    {
        head_ = node;
        tail_ = node;
    }
    else
    {
        node->next = head_;
        head_->prev = node;
        head_ = node;
    }

    return node;
}

void LRUCache::list_pop_back()
{
    if(!tail_) return;

    ListNode* node = tail_->prev;
    delete tail_;

    if(node == NULL)
    {
        head_ = NULL;
        tail_ = NULL;
    }
    else
    {
        node->next = NULL;
        tail_ = node;
    }
}

void LRUCache::list_move_front(ListNode* node)
{
    if(node == head_)
        return;

    if(node == tail_)
    {
        tail_->prev->next = NULL;
        tail_ = tail_->prev;
    }
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    node->prev = NULL;
    node->next = head_;

    head_->prev = node;  // Note!

    head_ = node;
}

// For DEBUG
void LRUCache::print_list()
{
    std::cout << "print head->tail:" << std::endl;
    ListNode* node = head_;
    while(node)
    {
        std::cout << node->key << " - " << node->value << std::endl;
        node = node->next;
    }

    std::cout << "print head<-tail:" << std::endl;
    node = tail_;
    while(node)
    {
        std::cout << node->key << " - " << node->value << std::endl;
        node = node->prev;
    }

    std::cout << "print end" << std::endl;
}
