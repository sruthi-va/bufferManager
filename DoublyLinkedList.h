// DoublyLinkedList.h
#pragma once

struct Node {
    int pageId;
    Node* prev;
    Node* next;

    Node(int id) : pageId(id), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void moveToFront(Node* node);
    void removeNode(Node* node);
    Node* addToFront(int pageId);
    Node* removeFromBack();
};
