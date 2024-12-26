#ifndef LIST_H
#define LIST_H

#include <functional> // For std::function

template<typename T>
class List {
    class Node {
    public:
        T data;      // Store object directly
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {} // Constructor for Node
    };

public:
    List();
    ~List();
    List& operator+=(const T& data);
    void traverse(std::function<void(T&)> func);
    void removeIf(std::function<bool(const T&)> condition);

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
        delete currNode;
        currNode = nextNode;
    }
}

template<typename T>
List<T>& List<T>::operator+=(const T& data) {
    Node* newNode = new Node(data);

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
        func(currNode->data); // Pass the object itself
        currNode = currNode->next;
    }
}

template<typename T>
void List<T>::removeIf(std::function<bool(const T&)> condition) {
    Node* currNode = head;
    Node* prevNode = nullptr;

    while (currNode != nullptr) {
        if (condition(currNode->data)) {
            // Remove the node
            Node* toDelete = currNode;
            if (prevNode) {
                prevNode->next = currNode->next;
            } else {
                head = currNode->next; // Update head if the first node is removed
            }
            currNode = currNode->next;
            delete toDelete;
        } else {
            prevNode = currNode;
            currNode = currNode->next;
        }
    }
}


#endif
