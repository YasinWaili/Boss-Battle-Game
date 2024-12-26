#ifndef LIST_H
#define LIST_H

#include <functional> // For std::function

template<typename T>
class List {
    class Node {
    public:
        T* data;
        Node* next;
    };

public:
    List();
    ~List();
    List& operator+=(T data);
    void traverse(std::function<void(T&)> func);
    void removeIf(std::function<bool(T&)> predicate);

private:
    Node* head;
};

template<typename T>
List<T>::List() : head(nullptr) {}

template<typename T>
List<T>::~List() {
    Node* currNode = head;
    while (currNode != nullptr) {
        Node* nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }
}

template<typename T>
List<T>& List<T>::operator+=(T data) {
    Node* newNode = new Node;
    newNode->data = new T(data);
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        Node* currNode = head;
        while (currNode->next != nullptr) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }

    return *this;
}

template<typename T>
void List<T>::traverse(std::function<void(T&)> func) {
    Node* currNode = head;
    while (currNode != nullptr) {
        func(*(currNode->data)); // Call function on data
        currNode = currNode->next;
    }
}

template<typename T>
void List<T>::removeIf(std::function<bool(T&)> predicate) {
    Node* currNode = head;
    Node* prevNode = nullptr;

    while (currNode != nullptr) {
        if (predicate(*(currNode->data))) { // Check condition
            Node* toDelete = currNode;

            if (prevNode == nullptr) { // Node is at the head
                head = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }

            currNode = currNode->next;

            delete toDelete->data; // Delete the data
            delete toDelete;       // Delete the node
        } else {
            prevNode = currNode;
            currNode = currNode->next;
        }
    }
}

#endif
