#include <iostream>

using namespace std;

# define MAX 10

class Stack {
private:
    int* arr;
    int size=MAX;
    int top=-1;
public:
    Stack() { arr = new int[MAX]; }
    Stack(int n) {
        arr = new int[n];
        size = n;
    }
    void push(int n);
    int pop();
    bool isEmpty();
    int length();
    int peek();
};

void Stack::push(int n) {
    if (top >= size - 1) {
        cout << "stack is full " << endl;
    }
    else {
        arr[++top] = n;
    }
}
int Stack::pop() {
    if (top == -1) {
        cout << "stack is empty" << endl;
        return -1;
    }
    else {
        int n = arr[top];
        arr[top--] = 0;
        return n;
    }
}

bool Stack::isEmpty() {
    return top == - 1;
}

int Stack::length() {
    return size;
}

int Stack::peek() {
    return arr[top];
}

int main()
{
    Stack stack = Stack(20);

    for (int i = 1; i <= stack.length(); i++) {
        stack.push(i);
    }

    stack.push(10);
    cout << "stack's top " << stack.peek() << endl;

    while (!stack.isEmpty()) {
        cout << stack.pop() << " ";
    }
    cout << endl;
    stack.pop();
}
