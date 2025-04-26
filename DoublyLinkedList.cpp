// DoublyLinkedList.cpp
#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void DoublyLinkedList::moveToFront(Node* node) {
    if (node == head) return;

    // Unlink node
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;

    if (node == tail) tail = node->prev;

    // Move to front
    node->prev = nullptr;
    node->next = head;
    if (head) head->prev = node;
    head = node;

    if (!tail) tail = head;
}

void DoublyLinkedList::removeNode(Node* node) {
    if (!node) return;
    
    if (node == head) head = node->next;
    if (node == tail) tail = node->prev;

    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;
}

Node* DoublyLinkedList::addToFront(int pageId) {
    Node* node = new Node(pageId);
    node->next = head;
    if (head) head->prev = node;
    head = node;
    if (!tail) tail = node;
    return node;
}

Node* DoublyLinkedList::removeFromBack() {
    if (!tail) return nullptr;
    Node* node = tail;
    removeNode(node);
    return node;
}
