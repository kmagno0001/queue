#include "node.hpp"

template<typename T>
class Queue {
public:
    ~Queue();
    template< typename... Args>
    Queue(const T first, const Args... param);
    void enqueue(const T param);
    const T front();
    const T back();
    void dequeue();

private:
    Node<T>* head;
    Node<T>* tail;
};

template< typename T>
template< typename... Args>
Queue<T>::Queue( const T first, const Args... param) {
    const T array[sizeof...(param)] { std::move(param)...};
    head = new Node<T> {first, nullptr, nullptr};
    Node<T>* tmp = head;
    for (auto i : array) {
        tmp->next = new Node<T> {i, tmp, nullptr};
        tmp = tmp->next;
    }

    tail = tmp;
}

template< typename T>
Queue<T>::~Queue() {
    Node<T>* tmp = tail;
    tail = tail->prev;
    delete tmp;

    this->~Queue();
}

template< typename T>
void Queue<T>::enqueue(const T param) {
    Node<T>* tmp = new Node<T> {param, nullptr, head};
    head->prev = tmp;
    head = tmp;
}

template< typename T>
const T Queue<T>::back() {
    return tail->value;
}

template< typename T>
const T Queue<T>::front() {
    return head->value;
}

template< typename T>
void Queue<T>::dequeue() {
    Node<T>* tmp = tail->prev;
    delete tail;
    tail = tmp;
}
