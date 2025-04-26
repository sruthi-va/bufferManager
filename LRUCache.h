// LRUCache.h
#pragma once
#include "DoublyLinkedList.h"
#include <unordered_map>

class LRUCache {
private:
    size_t capacity;
    DoublyLinkedList list;
    std::unordered_map<int, Node*> pageMap;

public:
    LRUCache(size_t capacity);

    void accessPage(int pageId);
    int evictPage(); // returns the evicted pageId
};
