// DiskManager.cpp
#include "DiskManager.h"
#include <iostream>
#include <cstring>

DiskManager::DiskManager() {}

DiskManager::~DiskManager() {}

void DiskManager::readPage(int pageId, char* pageData) {
    std::cout << "Reading page " << pageId << " from disk...\n";
    std::memset(pageData, pageId % 256, 4096); // Simulate content
}

void DiskManager::writePage(int pageId, const char* pageData) {
    std::cout << "Writing page " << pageId << " to disk...\n";
    // Could write to a file or just simulate
}
