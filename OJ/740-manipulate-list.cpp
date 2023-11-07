// ID: 740
// problem: Manipulate List

#include <cstdio>

class Node {
private:
    int val;
    Node* next;
public:
    Node(int val=0) {
        this->val = val;
        next = NULL;
    }
    int getVal() {
        return val;
    }
    void setVal(int val) {
        this->val = val;
    }
    Node* getNext() {
        return next;
    }
    void setNext(Node* next) {
        this->next = next;
    }
};

class List {
private:
    Node* first;
    void reverse(Node* head) {
        Node* prev = NULL;
        Node* cur = head;
        Node* next = NULL;
        while (cur) {
            next = cur->getNext();
            cur->setNext(prev);
            prev = cur;
            cur = next;
        }
        // return prev;
    }
public:
    List(int* arr=NULL, int n=0) {
        first = new Node();
        if (n == 0) {
            return;
        }
        Node* cur = first;
        for (int i = 0; i < n; i++) {
            Node* newNode = new Node(arr[i]);
            cur->setNext(newNode);
            cur = newNode;
        }
    }

    /* insert val after node at pos */
    void insert(int pos, int val) {
        Node* newNode = new Node(val);
        Node* cur = first;
        for (int i = 0; i < pos; i++) {
            cur = cur->getNext();
        }
        newNode->setNext(cur->getNext());
        cur->setNext(newNode);
    }

    /* delete node at pos */
    void remove(int pos) {
        Node* cur = first;
        for (int i = 1; i < pos; i++) {
            cur = cur->getNext();
        } // cur->next is pos
        Node* next = cur->getNext();
        cur->setNext(next->getNext());
        delete next;
    }

    /* reverse link from pos1 to pos2 */
    void reverse(int pos1, int pos2) {
        if (pos1 == pos2) {
            return;
        }
        Node* revStart = NULL;
        Node* revStartPrev = NULL;
        Node* revEnd = NULL;
        Node* revEndNext = NULL;
        Node* tmp = first;
        for (int i = 1; i < pos1; i++) {
            tmp = tmp->getNext();
        }
        revStartPrev = tmp;
        revStart = tmp->getNext();
        tmp = tmp->getNext();
        for (int i = pos1; i < pos2; i++) {
            tmp = tmp->getNext();
        }
        revEnd = tmp;
        revEndNext = tmp->getNext();

        // revStartPrev->setNext(NULL);
        revEnd->setNext(NULL);
        reverse(revStart);
        revStartPrev->setNext(revEnd);
        revStart->setNext(revEndNext);
    }

    /* query data at index pos */
    int query(int pos) {
        Node* cur = first;
        for (int i = 0; i < pos; i++) {
            cur = cur->getNext();
        }
        return cur->getVal();
    }

    /* DEBUG: print the full list */
    void print() {
        Node* cur = first->getNext();
        while (cur) {
            printf("%d ", cur->getVal());
            cur = cur->getNext();
        }
        printf("\n");
    }
};

int main() {
    int n;
    scanf("%d", &n);
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    List list(arr, n);
    int q;
    scanf("%d", &q);
    while (q--) {
        int op, para1, para2;
        scanf("%d", &op);
        switch (op) {
            case 1:
                scanf("%d %d", &para1, &para2);
                list.insert(para1, para2);
                break;
            case 2:
                scanf("%d", &para1);
                list.remove(para1);
                break;
            case 3:
                scanf("%d %d", &para1, &para2);
                list.reverse(para1, para2);
                break;
            case 4:
                scanf("%d", &para1);
                printf("%d\n", list.query(para1));
                break;
        }
        // list.print();
    }
}