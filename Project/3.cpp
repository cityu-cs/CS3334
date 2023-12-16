// Solution 3: Binary Search Tree

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 10000;

int arr[MAXN], ans[MAXN];

struct Node {
    int val, cnt;
    Node *lson, *rson;
    Node(int val) : val(val), cnt(1), lson(NULL), rson(NULL) {}
};

class BST {
private:
    Node *root;
    void insert(Node *node, int val) {
        if (val < node->val) {
            if (node->lson == NULL) {
                node->lson = new Node(val);
            } else {
                insert(node->lson, val);
            }
        } else if (val > node->val) {
            if (node->rson == NULL) {
                node->rson = new Node(val);
            } else {
                insert(node->rson, val);
            }
        } else {
            node->cnt++;
        }
    }

    Node* find(Node *node, int val) {
        if (node == NULL) {
            return NULL;
        }
        if (val < node->val) {
            return find(node->lson, val);
        } else if (val > node->val) {
            return find(node->rson, val);
        } else {
            return node;
        }
    }

public:
    BST() : root(NULL) {}
    void insert(int val) {
        if (root == NULL) {
            root = new Node(val);
        } else {
            insert(root, val);
        }
    }

    Node* find(int val) {
        return find(root, val);
    }
};

class Solution {
public:
    int solve(int arr[], int n, int ans[]) {
        BST bst;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            bst.insert(arr[i]);
        }
        for (int i = 0; i < n; i++) {
            Node *node = bst.find(arr[i]);
            if (node->cnt > 1) { // the node can't be NULL
                ans[cnt++] = arr[i];
                node->cnt = 0;
            }
        }
        return cnt;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int n = 0;
        int i = 0;
        while (i < line.length()) {
            int sign = 1;
            if (line[i] == '-') {
                sign = -1;
                i++;
            }
            int num = 0;
            while (i < line.length() && line[i] >= '0' && line[i] <= '9') {
                num = num * 10 + (line[i] - '0');
                i++;
            }
            arr[n++] = sign * num;
            i++;
        }

        int cnt = Solution().solve(arr, n, ans);
        if (cnt > 0) {
            printf("%d", ans[0]);
            for (int i = 1; i < cnt; i++) {
                printf(" %d", ans[i]);
            }
            printf("\n");
        }
    }
}
