#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 2;

struct Node {
    int data;
    int index;
    bool operator < (const Node &other) const {
        return data < other.data;
    }
    bool operator == (const Node &other) const {
        return index == other.index;
    }
};

template <typename T>
class Queue {
private:
    T arr[MAXN];
    int front, rear;
public:
    Queue() {
        front = rear = 0;
    }
    bool isEmpty() {
        return front == rear;
    }
    bool isFull() {
        return (rear + 1) % MAXN == front;
    }
    void push(T data) {
        if (isFull()) {
            return;
        }
        arr[rear] = data;
        rear = (rear + 1) % MAXN;
    }
    T pop() {
        if (isEmpty()) {
            return T();
        }
        T data = arr[front];
        front = (front + 1) % MAXN;
        return data;
    }
    T getFront() {
        if (isEmpty()) {
            return T();
        }
        return arr[front];
    }
    T get(int offset) {
        if (isEmpty()) {
            return T();
        }
        return arr[(front + offset) % MAXN];
    }
    void reset() {
        front = rear = 0;
    }
};

class Solution {
private:
    Queue<Node> q;
public:
    void solve(int n, int k, vector<int> s);
};

int main() {
    Solution sol;

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        sol.solve(n, k, s);
    }
}

void Solution::solve(int n, int k, vector<int> s) {
    for (int i = 0; i < n; i++) {
        q.push({s[i], i + 1});
    }
    for (int turn = 0; turn < n - 1; turn++) {
        int len = min(k, n - turn);
        Node maxNode = q.getFront();
        for (int i = 0; i < len; i++) {
            if (maxNode < q.get(i)) {
                maxNode = q.get(i);
            }
        }
        for (int i = 0; i < len; i++) {
            if (maxNode == q.getFront()) {
                cout << maxNode.index << " ";
                q.pop();
            } else {
                Node tmp = q.pop();
                q.push({tmp.data - 1, tmp.index});
            }
        }
    }
    cout << q.getFront().index << endl;
    q.reset();
}