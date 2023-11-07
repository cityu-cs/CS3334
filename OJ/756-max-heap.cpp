#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 2;

class Heap { // max heap
private:
    int arr[MAXN];
    int size = 0;
public:
    void insert(int x);
    void pop(); // remove the max element = root
    int sum();
};

int main() {
    int n;
    while (cin >> n) {
        Heap heap;
        while (n--) {
            char op;
            int x;
            cin >> op;
            switch(op) {
                case 'a':
                    cin >> x;
                    heap.insert(x);
                    break;
                case 'p':
                    heap.pop();
                    break;
                case 'r':
                    cout << heap.sum() << endl;
                    break;
            }
        }
    }
}

void Heap::insert(int x) {
    arr[++size] = x;
    int i = size;
    while (i > 1 && arr[i] > arr[i / 2]) {
        swap(arr[i], arr[i / 2]);
        i /= 2;
    }
}

void Heap::pop() {
    swap(arr[1], arr[size]);
    size--;
    int i = 1;
    while (i < size) {
        int maxIndex = i;
        if (i * 2 <= size && arr[i * 2] > arr[maxIndex]) {
            maxIndex = i * 2;
        }
        if (i * 2 + 1 <= size && arr[i * 2 + 1] > arr[maxIndex]) {
            maxIndex = i * 2 + 1;
        }
        if (maxIndex == i) {
            break;
        }
        swap(arr[i], arr[maxIndex]);
        i = maxIndex;
    }
}

int Heap::sum() {
    int sum = 0;
    for (int i = 1; i <= size; i++) {
        sum += arr[i];
    }
    return sum;
}
