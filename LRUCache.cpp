// LRUCache.cpp
#include "LRUCache.h"

LRUCache::LRUCache(size_t capacity) : capacity(capacity) {}

void LRUCache::accessPage(int pageId) {
    if (pageMap.find(pageId) != pageMap.end()) {
        Node* node = pageMap[pageId];
        list.moveToFront(node);
    } else {
        if (pageMap.size() >= capacity) {
            Node* evicted = list.removeFromBack();
            if (evicted) {
                pageMap.erase(evicted->pageId);
                delete evicted;
            }
        }
        Node* newNode = list.addToFront(pageId);
        pageMap[pageId] = newNode;
    }
}

int LRUCache::evictPage() {
    Node* node = list.removeFromBack();
    if (!node) throw std::runtime_error("Cannot evict from empty cache!");

    int pageId = node->pageId;
    pageMap.erase(pageId);
    delete node;
    return pageId;
}
