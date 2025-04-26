// BufferManager.h
#pragma once
#include "BufferPool.h"

class BufferManager {
private:
    BufferPool* bufferPool;

public:
    BufferManager(size_t poolSize);
    ~BufferManager();

    Page* getPage(int pageId);
    void unpinPage(int pageId);
    void flushPage(int pageId);
};
