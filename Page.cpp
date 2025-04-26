// Page.cpp
#include "Page.h"
#include <cstring>

Page::Page(int id) : pageId(id), isDirty(false), pinCount(0) {
    data = new char[4096]; // Assume 4KB pages
    std::memset(data, 0, 4096);
}

Page::~Page() {
    delete[] data;
}

void Page::markDirty() {
    isDirty = true;
}

void Page::pin() {
    pinCount++;
}

void Page::unpin() {
    if (pinCount > 0) {
        pinCount--;
    }
}
