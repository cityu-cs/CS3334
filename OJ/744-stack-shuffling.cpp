#include <cstdio>

class Stack {
private:
    int top;
    int cap;
    int* val;
public:
    Stack(int initCap=100) {
        top = -1;
        cap = initCap;
        val = new int[cap];
    }

    int peek() {
        return val[top];
    }

    int pop() {
        // int res = val[top--];
        // if (top < cap / 4) {
        //     reallocate(cap / 2);
        // }
        // return res;
        return val[top--];
    }

    void push(int arg) {
        val[++top] = arg;
        // if (top == cap - 1) {
        //     reallocate(cap * 2);
        // }
    }

    void reallocate(int newCap) {
        cap = newCap;
        int* newVal = new int[cap];
        for (int i = 0; i <= top; i++) {
            newVal[i] = val[i];
        }
        delete val;
        val = newVal;
    }

    void resize(int newCap) {
        cap = newCap;
        top = -1;
        delete val;
        val = new int[cap];
    }

    void reset() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    int t, n, m;
    int* a;
    int* b;
    scanf("%d", &t);
    Stack s;
    while (t--) {
        scanf("%d", &n);
        a = new int[n];
        b = new int[n];
        s.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        scanf("%d", &m);
        while (m--) {
            for (int i = 0; i < n; i++) {
                scanf("%d", b + i);
            }
            int aidx = n - 1;
            int bidx = 0;
            bool flag = true;
            while (aidx >= 0 || bidx < n) {
                if (aidx >= 0 && a[aidx] == b[bidx]) {
                    // printf("A->S->B: %d\n", a[aidx]);
                    aidx--;
                    bidx++;
                } else if (!s.isEmpty() && s.peek() == b[bidx]) {
                    // printf("S->B: %d\n", b[bidx]);
                    s.pop();
                    bidx++;
                } else if (aidx >= 0) {
                    s.push(a[aidx]);
                    // printf("A->S: %d\n", a[aidx]);
                    aidx--;
                } else {
                    flag = false;
                    break;
                }
            }
            puts(flag ? "Aye" : "Impossible");
            s.reset();
        }
    }
}