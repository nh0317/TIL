#include <iostream>

using namespace std;

# define MAX 10

class Queue {
private:
    int size = MAX;
    int* arr;
    int head = 0;
    int tail = 0;
public : 
    Queue() { arr = new int[size+1]; }
    Queue(int n) { arr = new int[n+1]; size = n +1; }
    void push(int n);
    int pop();
    bool isEmpty();
    int length();
    int peek();
};

void Queue::push(int n) {
    //cout << n << " " << tail << " " << head << endl;
    if ((tail+1) % size == head) {
        cout << "queue is full" << endl;
    }
    else {
        tail = (tail + 1) % size;
        arr[tail] = n;
    }
}
int Queue::pop() {
    if (head == tail) {
        cout << "queue is Empty" << endl;
    }
    else {
        head = (head + 1) % size;
        return arr[head];
    }
}
int Queue::length() {
    return size-1;
}

bool Queue::isEmpty() {
    return head == tail;
}
int Queue::peek() {
    return arr[(head + 1) % size];
}

int main()
{
    Queue que = Queue(20);

    for (int i = 1; i <= que.length(); i++){
        que.push(i);
    }
    que.push(10);
    cout <<"queue's top is " <<que.peek() << endl;

    while (!que.isEmpty()) {
        cout << que.pop() << " ";
    }
    cout << endl;
    que.pop();
}
