// BufferPool.cpp
#include "BufferPool.h"
#include <iostream>

BufferPool::BufferPool(size_t capacity) : capacity(capacity) {}

BufferPool::~BufferPool() {
    for (auto& entry : pageTable) {
        delete entry.second;
    }
}

Page* BufferPool::fetchPage(int pageId) {
    if (pageTable.find(pageId) != pageTable.end()) {
        // Hit
        lruList.remove(pageId);
        lruList.push_front(pageId);
        pageTable[pageId]->pin();
        return pageTable[pageId];
    }

    // Miss
    if (pageTable.size() >= capacity) {
        evictPage();
    }

    Page* newPage = new Page(pageId);
    pageTable[pageId] = newPage;
    lruList.push_front(pageId);
    newPage->pin();
    return newPage;
}

void BufferPool::releasePage(int pageId) {
    if (pageTable.find(pageId) != pageTable.end()) {
        pageTable[pageId]->unpin();
    }
}

void BufferPool::flushPage(int pageId) {
    if (pageTable.find(pageId) != pageTable.end()) {
        if (pageTable[pageId]->isDirty) {
            std::cout << "Flushing page " << pageId << " to disk.\n";
            pageTable[pageId]->isDirty = false;
        }
    }
}

void BufferPool::evictPage() {
    for (auto it = lruList.rbegin(); it != lruList.rend(); ++it) {
        int candidateId = *it;
        Page* candidate = pageTable[candidateId];
        if (candidate->pinCount == 0) {
            flushPage(candidateId);
            delete candidate;
            pageTable.erase(candidateId);
            lruList.remove(candidateId);
            std::cout << "Evicted page " << candidateId << "\n";
            return;
        }
    }
    throw std::runtime_error("No unpinned pages available for eviction!");
}
