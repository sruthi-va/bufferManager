// Page.h
#pragma once
#include <cstddef>

class Page {
public:
    int pageId;
    bool isDirty;
    int pinCount;
    char* data;

    Page(int id);
    ~Page();

    void markDirty();
    void pin();
    void unpin();
};
