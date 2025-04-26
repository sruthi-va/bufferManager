// BufferManager.cpp
#include "BufferManager.h"

BufferManager::BufferManager(size_t poolSize) {
    bufferPool = new BufferPool(poolSize);
}

BufferManager::~BufferManager() {
    delete bufferPool;
}

Page* BufferManager::getPage(int pageId) {
    return bufferPool->fetchPage(pageId);
}

void BufferManager::unpinPage(int pageId) {
    bufferPool->releasePage(pageId);
}

void BufferManager::flushPage(int pageId) {
    bufferPool->flushPage(pageId);
}
