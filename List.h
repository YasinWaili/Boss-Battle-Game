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
    void traverse(std::function<void(T&)> func); // Add traversal method

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
        if (!currNode->data) {
            return;
        }
        func(*(currNode->data)); // Pass the data to the function
        currNode = currNode->next;
    }
}
