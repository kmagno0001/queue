#include <iostream>
#include "Queue.hpp"

int main() {
    Queue q {10,12,13,14};
    q.enqueue(5);
    q.dequeue();

    std::cout << q.back() << " " << q.front();

    for (int i=0; i < 4; ++i) {
        std::cout <<" "<< q.back() << " ";
        q.dequeue();
    }

    return 0;
}