// DiskManager.h
#pragma once
#include <string>

class DiskManager {
public:
    DiskManager();
    ~DiskManager();

    void readPage(int pageId, char* pageData);
    void writePage(int pageId, const char* pageData);
};
