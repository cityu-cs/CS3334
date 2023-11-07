// 98: Trees

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500 + 1;

class UnionFind {
public:
    int fa[MAXN];
    bool in_cycle[MAXN];
    int n;
    int trees;

    UnionFind(int n): n(n), trees(n) {
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            in_cycle[i] = false;
        }
    }

    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (in_cycle[x] && in_cycle[y]) {
            return;
        }
        trees--;
        if (x == y) {
            in_cycle[x] = true;
            return;
        }
        if (in_cycle[x]) {
            fa[y] = x;
        } else {
            fa[x] = y;
        }
    }
};

int main() {
    int n, m;
    int t = 0;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        UnionFind uf(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            uf.unite(x, y);
        }
        cout << "Case " << ++t << ": ";
        switch (uf.trees) {
            case 0:
                cout << "No trees." << endl;
                break;
            case 1:
                cout << "There is one tree." << endl;
                break;
            default:
                cout << "A forest of " << uf.trees << " trees." << endl;
        }
    }
}
