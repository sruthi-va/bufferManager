// BufferPool.h
#pragma once
#include "Page.h"
#include <unordered_map>
#include <list>

class BufferPool {
private:
    size_t capacity;
    std::unordered_map<int, Page*> pageTable;
    std::list<int> lruList; // List of pageIds
    void evictPage();

public:
    BufferPool(size_t capacity);
    ~BufferPool();
    
    Page* fetchPage(int pageId);
    void releasePage(int pageId);
    void flushPage(int pageId);
};
