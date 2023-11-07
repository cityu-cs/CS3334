#include <cstdio>

struct job {
    int id;
    int priority;

    job(int i=-1, int p=-1): id(i), priority(p) {}

    bool operator < (const job& rhs) {
        return this->priority < rhs.priority;
    }
};

const int N = 101;

template<typename T>
struct queue {
    int front = 0;
    int rear = 0;
    T arr[N];

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % N == front;
    }

    void enqueue(T e) {
        if (isFull())
            return;
        arr[rear] = e;
        rear = (rear + 1) % N;
    }

    T dequeue() {
        // if (isEmpty())
        //     return NULL;
        T e = arr[front];
        front = (front + 1) % N;
        return e;
    }

    void reset() {
        front = 0;
        rear = 0;
    }

    T getId(int id) {
        return arr[(front + id) % N];
    }
};

int main() {
    int t;
    scanf("%d", &t);
    queue<job> q;
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            int p;
            scanf("%d", &p);
            q.enqueue(job(i, p));
        }
        int timestamp = 1;
        while (timestamp <= n) {
            job cur = q.dequeue();
            int queuesize = n - timestamp;
            bool flag = false;
            for (int i = 0; i < queuesize; i++) {
                if (cur < q.getId(i)) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                q.enqueue(cur);
            } else {
                if (cur.id == m) {
                    printf("%d\n", timestamp);
                    break;
                }
                timestamp++;
            }
        }
        q.reset();
    }
}