#include <iostream>

class MinHeap {
public:
    int arr[100];
    int size;

    MinHeap() {
        size = 0;
    }
    void swapValues(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void push(int value) {
        size++;
        arr[size] = value;
        int i = size;
        while (i > 1 && arr[i] < arr[i / 2]) {
            swapValues(arr[i], arr[i / 2]);
            i = i / 2;
        }
    }

    int top() {
        if (size == 0) return -1;
        return arr[1];
    }

    void pop() {
        if (size == 0) return;

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (true) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int smallest = i;

            if (left <= size && arr[left] < arr[smallest]) {
                smallest = left;
            }
            if (right <= size && arr[right] < arr[smallest]) {
                smallest = right;
            }
            if (smallest == i) break;

            swapValues(arr[i], arr[smallest]);
            i = smallest;
        }
    }

    bool empty() {
        return size == 0;
    }
};

int main() {
    MinHeap pq;

    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(3);

    std::cout << pq.top() << "\n";
    pq.pop();

    std::cout << pq.top() << "\n";
    pq.pop();

    std::cout << pq.top() << "\n";
    pq.pop();

    return 0;
}
