// 749: Tree Reconstruction

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

const int MAXN = 100 + 2;

int n, pre[MAXN], in[MAXN];

void reconstruct(int preStart, int preEnd, int inStart, int inEnd, Node *&root) {
    if (preStart > preEnd) {
        root = NULL;
        return;
    }
    root = new Node;
    root->data = pre[preStart];
    int i;
    for (i = inStart; i <= inEnd; i++) {
        if (in[i] == pre[preStart]) {
            break;
        }
    }
    reconstruct(preStart + 1, preStart + i - inStart, inStart, i - 1, root->left);
    reconstruct(preStart + i - inStart + 1, preEnd, i + 1, inEnd, root->right);
}

void postOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data;
    if (root->data != pre[0]) {
        cout << " ";
    } else {
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> pre[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        Node *root;
        reconstruct(0, n - 1, 0, n - 1, root);
        postOrder(root);
    }
}